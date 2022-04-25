class Shape  //Abstract Class
{
  public:
  int length, breadth;
  // Shape(int length,int breadth): length{length},breadth{breadth} {}
  virtual int getArea()=0;  //Pure Virtual Function


};
class Rectangle: public Shape
{
 public:
 Rectangle(int length, int breadth)
 {
  this->length=length;
  this->breadth=breadth;
 }
 int getArea()
 {
  cout<<"Area of Rectangle:"<<length*breadth<<endl;
 }
};
class Square: public Shape
{
 public:
 Square(int length)
 {
  this->length=length;
 }
 int getArea()
 {
  cout<<"Area of Sqaure:"<<length*length<<endl;
 }
};


signed main()
{
  Rectangle rect(10,30);
  rect.getArea();
  Square sq(6);
  sq.getArea();
}
