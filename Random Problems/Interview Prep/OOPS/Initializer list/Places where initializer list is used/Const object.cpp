class employee
{
  public:
  const int age;
 //Parametrized Constructor using initializer list
 employee(int age1): age(age1){}
 /*
  You cannot do this in case of const data member:
   employee(int age1){age=age1;}
   This will produce error, because this is an assignment, not initilization
 */
};

signed main()
{
  employee devansh(22);
}
