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
class E: public C
{
 public:
 int e;
 E()
 {
  cout<<"E called"<<endl;
 };
};

class F: public C
{
 public:
 int f;
 F()
 {
  cout<<"F called"<<endl;
 };
};


signed main()
{
  freopen
  ios
  F f;
}
/*
Output:
A called
C called
F called
*/
