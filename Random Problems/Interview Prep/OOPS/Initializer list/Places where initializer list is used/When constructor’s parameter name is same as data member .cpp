class A
{ 
  public:
  int var;
  A(int var) {var=var;}
  /*
  We cannot do like this:
   A(int var): 
   {
     var=var; //no error will be shown, but value will not be assigned, this point should be used.
   }
  */
};
signed main()
{
  freopen
  ios
  A obj(1);
  cout<<obj.var<<endl;
}
