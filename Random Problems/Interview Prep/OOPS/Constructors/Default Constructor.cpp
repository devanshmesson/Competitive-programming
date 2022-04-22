class employee
{
  public:
  string company;
  int age;
  string password;
  char name[100];
  
  //Default Constructor (no arguments taken)
  employee()
  {
    cout<<"Constructor Called"<<endl;
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
  freopen
  ios
  //static allocation
  employee devansh;

  //dynamic allocation
  employee *parth=new employee();
  
  /*
  For dynamic allocation 
  Another syntax (add round brackets):
  employee *parth=new employee();
  */
}

/*
Output :
Constructor Called
Constructor Called

*/
