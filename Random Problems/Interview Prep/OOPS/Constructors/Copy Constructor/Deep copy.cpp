//Deep copy is done by user defined data copy constructor.
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
  }

};

signed main()
{
  freopen
  ios
  char name[]="devansh";
  employee devansh("Amazon",21,name);
  
  //copying the object
  employee divyam=devansh;
  cout<<"New Object details:"<<endl;
  
  //After copying, Suppose I changed the name of devansh object
  devansh.name[0]='V';
  
  /*
  Updated name will be not reflected in the new object "divyam".
  Because, The user define copy constructor created a deep copy 
  of the old object, which means If some variables are dynamically 
  allocated from heap section, then copied object variable 
  will dynamically assign new memory and then copy the values.
  This way, if there is some change in the values of  dynamically allocated 
  variables, then there will be no change reflected because
  they are two different memory locations. 
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
