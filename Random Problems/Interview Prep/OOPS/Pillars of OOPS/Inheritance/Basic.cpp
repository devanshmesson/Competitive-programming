class Human
{
  public:
  int age;
  int weight;
  string name;

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
};


signed main()
{
  Male m;
  //Child class object accesss data members and member functions 
  m.setAge(22);
  cout<<"Male's age is:"<<m.getAge()<<endl;
  m.sleep();
}

/*
Output:
Male's age is:22
Male is sleeping

*/
