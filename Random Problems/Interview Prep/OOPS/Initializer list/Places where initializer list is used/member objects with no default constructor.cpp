class A
{
  public:
  //class A does not have default constructor
  int var;
  A(int z){var=z;}
};
class B
{ 
  public:
  //A's object is a data member in class B.
  A object_a;
  B(A object_b): object_a{object_b} {}

  /*
  We cannot do like this:
  B(A object_b){ object_a=object_b; }

  Because object_a is just created with no parameter, which means
  it should call a default constructor but there is no
  default constructor in A.

  So, A should be initialized with another object.
  It acts as a copy constructor.
  */
};
signed main()
{
  A obj_a(10);
  B obj_b(obj_a);
}
