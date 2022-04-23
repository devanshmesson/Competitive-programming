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
    cout<<endl;
  }

};

signed main()
{
  char name1[]="devansh";
  employee devansh("Amazon",22,name1);
  char name2[]="parth";
  employee parth("Google",23,name2);

  cout<<"Before Applying Assignment operator"<<endl;
  devansh.print();
  parth.print();

  //Applying assignment operator
  devansh=parth;

  cout<<"\nAfter Applying Assignment operator"<<endl;
  devansh.print();
  parth.print();
}
/*
Output:
Before Applying Assignment operator
Name:devansh
Age:22
Company:Amazon

Name:parth
Age:23
Company:Google


After Applying Assignment operator
Name:parth
Age:23
Company:Google

Name:parth
Age:23
Company:Google


*/
