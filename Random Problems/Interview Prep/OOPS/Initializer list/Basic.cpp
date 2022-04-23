class employee
{
  public:
  string company;
  int age;
  string password;
  string name;
  
 //Parametrized Constructor using initializer list
 employee(string company, int age, string name): company{company},age{age},name{name} {}
  
 /*
 Another syntax:
 Use round brackets while initializing like this:
 employee(string company, int age, string name): company(company),age(age),name(name) {}
 But this is not preffered because this will not give warning if
 we are assigning a big data type to small data type.
 
 so always use curly braces.
 */

};

signed main()
{
  string name1="devansh";
  employee devansh("Amazon",22,name1);
  cout<<devansh.name<<endl;
}
