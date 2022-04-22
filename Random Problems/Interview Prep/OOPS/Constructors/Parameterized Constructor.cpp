class employee
{
  public:
  string company;
  int age;
  string password;
  string name;
  
  //Parametrized Constructor (No default constructor exits)
  employee(string company, int age)
  {
    cout<<"Constructor 1 called"<<endl;
    this->company=company;
    this->age=age;
  }
 employee(string company, int age, string name)
  {
    cout<<"Constructor 2 called"<<endl;
    this->company=company;
    this->age=age;
    this->name=name;
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

};

signed main()
{

  employee devansh("Amazon",21);
  employee *parth=new employee("Google",22,"Parth");

  /*
    employee *divyam=new employee;
    This will give error, because there is no
    default constructor. But We can make one.
  */
}
