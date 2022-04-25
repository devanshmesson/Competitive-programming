class Sum
{
  private:
  int a,b;   //Hinding the data members
  public:
  int add(int a,int b) //Hiding the implementation detail
  {
    return a+b;
  }
};


signed main()
{
  Sum s;
  cout<<s.add(1,2)<<endl;
}

