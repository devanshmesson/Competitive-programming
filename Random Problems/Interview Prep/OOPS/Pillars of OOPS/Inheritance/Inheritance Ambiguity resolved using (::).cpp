//Inheritance Ambiguity resolved using Scope resolution operator
class A
{
 public:
 int a;

 void sleep()
 {
  cout<<"A is sleeping"<<endl;
 }
};

class B
{
 public:
 int a;
 void sleep()
 {
  cout<<"B is sleeping"<<endl;
 }
};
class C: public A,public B
{
 public:
 int c;
};

/*
A  B
\  /
 C
*/


signed main()
{
 
  C c;
  //c.sleep(); //Produces error, sleep is ambiguous
  //Solution 
  c.A::sleep();
  c.B::sleep();

  // cout<<c.a<<endl; //Produces error, sleep is ambiguous
  //Solution
  cout<<c.A::a<<endl; //Garbage value
  cout<<c.B::a<<endl; //Garbage value
}
/*
Output:
A is sleeping
B is sleeping
4201104
6422352

*/
