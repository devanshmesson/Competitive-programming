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

class Male: protected Human
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
 /*
 int getIncome()
 {
  return this->income; //this will produce error,because income is not available in derived class.
 }
 */

 int getAge()
 {
  return this->age;
 }
 int setAge(int age)
 {
  this->age=age;
 }

};


signed main()
{
  Male m;
  /*
  Access mode: protected
  public members of base class have protected access mode
  in derived class.
  */
  // cout<<m.age<<endl; //This will produce error
  m.setAge(22); //Modifying protected members through setter
  cout<<m.getAge()<<endl; //Accessing protected members through getter

  //---------------------------------------------------------

  /*
  Access mode: protected
  protected members of base class have protected access mode
  in derived class.
  */
  //cout<<m.weight<<endl;//This will produce error
  cout<<m.getWeight()<<endl; //Accessing protected members through getter

  //---------------------------------------------------------

  /*
  Access mode: protected
  private members of base class have no access in derived class.
  They are not present in derived class.
  */

  // cout<<m.income<<endl; // this will produce error
  cout<<m.getAge()<<endl; //getAge() will produce error


}
