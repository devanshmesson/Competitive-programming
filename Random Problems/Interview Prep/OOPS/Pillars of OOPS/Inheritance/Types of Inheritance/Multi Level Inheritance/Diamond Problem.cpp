class A
{
 public:
 int a;
 A()
 {
  cout<<"A called"<<endl;
 }
};

class B: public A
{
 public:
 int b;
 B()
 {
  cout<<"B called"<<endl;
 }
};
class C: public A
{
 public:
 int c;
 C()
 {
  cout<<"C called"<<endl;
 }
};
class D: public C,public B
{
 public:
 int d;
 D()
 {
  cout<<"D called"<<endl;
 }
};

/*
  Demonstration of Diamond Problem.
   A
  /\
 B  C
 \  /
   D 
*/

signed main()
{
  D obj;
  cout<<obj.b<<endl;//Executes successfully
  cout<<obj.c<<endl;//Executes successfully
  cout<<obj.d<<endl;//Executes successfully
  cout<<obj.a<<endl; //Produces error: request for member a is ambiguous


}
