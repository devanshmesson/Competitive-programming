class A
{
 public:
 static int object_count;
 A(){object_count++;}
};

int A::object_count=0;
//syntax:  datatype classname::variablename=value;
//Initialized outside main() in order to be accessed by everyone.
signed main()
{
  A obj1,obj2;
  cout<<"Total objects:"<<A::object_count<<endl;
}
