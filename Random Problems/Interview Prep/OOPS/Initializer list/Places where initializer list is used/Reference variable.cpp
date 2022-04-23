class employee
{
  public:
  int& reference; //reference variable
 
 //Parametrized Constructor using initializer list
 employee(int original): reference{original} {}

 /*
  You cannot do this in case of reference data member:
   employee(int original){reference=original;}
   This will produce error, Reference variable should be initialized at the time of declaration.
   It cant be assigned if no initialization is done.
 */
};

signed main()
{
  employee devansh(22);
  cout<<devansh.reference<<endl; //outputs 22
}
