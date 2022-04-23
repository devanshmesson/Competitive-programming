//Shallow copy is done by default copy constructor.
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
  char name[]="devansh";
  employee devansh("Amazon",21,name);
  
  //copying the object
  employee divyam=devansh;
  cout<<"New Object details:"<<endl;
  
  //After copying, Suppose I changed the name of devansh object
  devansh.name[0]='V';
  
  /*
  Updated name will be reflected in the new object "divyam" too.
  Because, The default copy constructor created a shallow copy 
  of the old object, which means If some variables are dynamically 
  allocated memory from heap section, then copied object variable 
  will also reference to the same memory location.
  */
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
Name:Vevansh
Age:21
Company:Amazon

Old Object details:
Name:Vevansh
Age:21
Company:Amazon
*/
