class A
{
 public:
 static int object_count; //declaration
 int var;

 static int random()
 {
   /*
   cout<<var<<endl;
   This will produce error as static member functions cannot access 
   non static data members.
   */
   
   cout<<object_count<<endl;   
 }
};

int A::object_count=100;
//syntax:  datatype classname::variablename=value;
signed main()
{
  
  A::random();
  //syntax to call static funtion is classname::static_function_name

  //Static member functions can also be called through objects
  A obj;
  obj.random();
  
}
