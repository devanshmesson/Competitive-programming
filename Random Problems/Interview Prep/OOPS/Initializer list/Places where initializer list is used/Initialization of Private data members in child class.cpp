class parent
{
  int par_var;
  public:
  parent(int z){par_var=z;}
};
class child: public parent
{ 
  public:
  //A's object is a data member in class B.
  int derived;
  child(int par, int child_): parent{par},derived{child_} {}
  //Here we are calling the constructor, so its possible.

  /*
  We cannot do like this:
   child(int par, int child_)
   {
     par_var=par; // this cant be done because its private data member.
     derived=child_;  //this can still be done as its of same class
   }
  */
};
signed main()
{
 
  child c(1,2);
}
