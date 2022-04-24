
class vehicle
{
 public:
 vehicle()
 {
  cout<<"This is a vehicle"<<endl;
 }
};
class FourWheeler: public vehicle
{
 public:
 FourWheeler()
 {
  cout<<"This is a Four FourWheeler"<<endl;
 }
};
class Car: public FourWheeler
{
 public:
 Car()
 {
  cout<<"This is a car"<<endl;
 }
};


signed main()
{
  Car c;
}
/*
Output:
This is a vehicle
This is a Four FourWheeler
This is a car

*/
