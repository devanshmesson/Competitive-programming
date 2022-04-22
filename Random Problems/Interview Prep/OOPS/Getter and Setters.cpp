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
  employee devansh;
  //Change a private data member using public member function
  devansh.setcompany("Amazon","abcd");
  //Get a private data member using public member function
  cout<<devansh.getcompany()<<endl;
}
