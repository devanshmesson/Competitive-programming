class employee
{
  string company;
  int age;
  string password;
  char name[100];

  public:
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
  //static allocation
  employee devansh;
  devansh.setcompany("Amazon","abcd");
  cout<<devansh.getcompany()<<endl;

  //dynamic allocation
  employee *parth=new employee;
  (*parth).setcompany("Google","abcd");
  cout<<parth->getcompany()<<endl
  
  /*
    Accessing data members and function in case of
    dynamic allocation:

    using (.) operator - (*parth).getcompany();
    using (->) operator - parth->getcompany();
  */
}
