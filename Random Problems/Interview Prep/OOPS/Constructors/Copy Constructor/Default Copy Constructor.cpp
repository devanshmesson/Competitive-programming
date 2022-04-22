//Compiler has its own copy constructor, if there is no user defined copy constructor
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
 
  //setter 
  void setcompany(string comp,string password)
  {
    if(password=="abcd")company=comp;
  }
  //getter
  string getcompany()
  {
    return company;
  }
  void print()
  {
    cout<<"Name:"<<name<<endl;
    cout<<"Age:"<<age<<endl;
    cout<<"Company:"<<company<<endl;
  }

};

signed main()
{
  char n[]="devansh";
  employee devansh("Amazon",21,n);
  employee *parth=new employee("Google",22,n);
  
  //Copying the object, and default copy constructor will be invoked.
  employee divyam=devansh;
  divyam.print();
  cout<<endl;
  devansh.print();

  /*
   Another syntax to copy the object:
    employee new_object(old_object);
  */
}
