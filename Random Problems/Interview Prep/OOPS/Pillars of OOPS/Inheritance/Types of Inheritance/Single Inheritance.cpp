class Human
{
  public:
  int weight;
  int age;
  string name;

  Human()
  {
    cout<<"This is a Human"<<endl;
  }
};

class Male: public Human
{
  public:
  Male()
  {
    cout<<"This is a Male"<<endl;
  }
};


signed main()
{
  Male m;
}
/*
Output:
This is a Human
This is a Male

*/
