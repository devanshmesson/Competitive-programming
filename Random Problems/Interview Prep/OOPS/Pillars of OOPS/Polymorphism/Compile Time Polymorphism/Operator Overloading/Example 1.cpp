class Complex
{
  public:
  int real;
  int imag;
  Complex(){}
  Complex(int real,int imag): real{real},imag{imag} {}
  
  Complex operator +(Complex &c)
  {
    Complex result;
    result.real=this->real + c.real;
    result.imag=this->imag + c.imag;
    return result;
  }
};
signed main()
{
  Complex c1(1,2);
  Complex c2(5,6);
  Complex c4(10,19);
  Complex c3=c1.operator+(c2); //Copy constructor
  //Remove .operator and we can also write like the following:
  c3=c1+c2;
  cout<<c3.real<<" "<<c3.imag<<endl;

  c3=c1+c2+c3;
  /*
  c3=c1.operator+(c2).operator+(c4);
  */
  cout<<c3.real<<" "<<c3.imag<<endl;
}
