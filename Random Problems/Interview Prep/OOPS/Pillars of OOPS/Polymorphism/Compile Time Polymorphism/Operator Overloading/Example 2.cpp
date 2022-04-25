//Used Minus operator to negate a value.
class Integer
{
  public:
  int val;
  Integer(){}
  Integer(int val): val{val} {}
  Integer operator -()
  {
    Integer result;
    result.val=-1*(this->val);
    return result;
  }


};
signed main()
{
  Integer a(5);
  Integer b=-a;
  /*
  minus is used as unary operator to negate the value of a and 
  assign it to b.

  We can also write above statement as:
  Integer b=a.operator-();

  */
  cout<<"value of a:"<<a.val<<endl;
  cout<<"value of b:"<<b.val<<endl;

}
