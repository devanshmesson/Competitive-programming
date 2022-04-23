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
  //User defined copy constructor
  employee(employee &old_emp)
  {
    company=old_emp.company;
    age=old_emp.age;
    this->name=new char[strlen(old_emp.name)+1];
    strcpy(name,old_emp.name);
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

  char name[]="devansh";
  employee devansh("Amazon",21,name);
  
  //copying the object
  employee divyam=devansh;
  cout<<"New Object details:"<<endl;
  divyam.print();
  cout<<endl;
  cout<<"Old Object details:"<<endl;
  devansh.print();

  /*
   Another syntax to copy the object:
    employee new_object(old_object);
  */

}
/*
New Object details:
Name:devansh
Age:21
Company:Amazon

Old Object details:
Name:devansh
Age:21
Company:Amazon

*/
