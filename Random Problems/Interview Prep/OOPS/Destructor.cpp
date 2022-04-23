class employee
{
  public:
  string company;
  int age;
  string password;
  char *name;
  
  employee()
  {
    cout<<"Default constructor called"<<endl;
  }
  //Parametrized Constructor 
  employee(string company, int age)
  {
    this->company=company;
    this->age=age;
  }
  //Parametrized Constructor 
 employee(string company, int age, char *name)
  {
    this->company=company;
    this->age=age;
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
  }
  ~employee()
  {
    cout<<"Destructor called"<<endl;
  }

};

signed main()
{
  char name1[]="devansh";
  employee devansh("Amazon",22,name1);
  char name2[]="parth";
  employee *parth=new employee("Google",23,name2);
  //Explicitly call destructor(by using delete operator) to free dynamicaly allocated memory
  //If delete is not used then, destructor for parth will not be called.
  delete parth;
}
/*
Output - 
Destructor called
Destructor called

*/
