class Human
{
  protected:
  int weight;

  public:
  int age;
  string name;

  private:
  int income;
  
  public:
  int getAge()
  {
    return this->age;
  }
  void setAge(int age)
  {
    this->age=age;
  }
};

class Male: public Human
{
 public:
 int skin_color;
 void sleep()
 {
  cout<<"Male is sleeping"<<endl;
 }
 int getWeight()
 {
  return this->weight;
 }
 int getIncome()
 {
  return this->income; //this will produce error,because income is not available in derived class.
 }

};


signed main()
{
  freopen
  ios
  Male m;
  m.setAge(22);
  /*
  Access mode: public
  public data members of base class are publicly accessible
  for derived class.
  */
  cout<<m.age<<endl;
  //---------------------------------------------------------
  
  /*
  Access mode: public
  protected data members of base class are not accessible publicly
  for derived class.

  They are protected in derived class.
  They can be accessed inside base class or derived class
  */
  //cout<<m.weight<<endl; // it will produce error

  //Can access protected member of derived class through getter. 
  cout<<m.getWeight()<<endl;

  //---------------------------------------------------------
  /*
  Access mode: public
  private data members of base class are not accessible in derived class.
  Note:
  Private member of base class can only be accessed by getter of base class.
  */

  cout<<m.getIncome()<<endl; //this will produce error
  cout<<m.income<<endl;
}
