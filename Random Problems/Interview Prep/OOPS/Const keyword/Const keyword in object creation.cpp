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
  employee(string company)
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
    //Newly allocated memory, avoids shallow copying by doing deep copy.
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
    cout<<endl;
  }
  ~employee()
  {
    cout<<"Destructor called"<<endl;
  }

};

signed main()
{
  
  char name1[]="devansh";
  const employee devansh("Amazon",22,name1);
  devansh.setcompany("v","abcd");  //This statement produces an error.
}
