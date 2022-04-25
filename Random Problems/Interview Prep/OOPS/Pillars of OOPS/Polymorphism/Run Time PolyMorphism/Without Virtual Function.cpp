class Shape
{
  public:
  int getArea()  //Virtual Function
  {
    cout<<"Area of Shape"<<endl;
  }
};
class Rectangle: public Shape
{
 public:
 int getArea()
 {
  cout<<"Area of Rectangle"<<endl;
 }
};
class Square: public Rectangle
{
 public:
 int getArea()
 {
  cout<<"Area of Sqaure"<<endl;
 }
};


signed main()
{
  Square sq;
  sq.getArea(); //Output: Area of square
  Rectangle rect;
  rect.getArea(); //Output: Area of Rectangle
  /*
  If we remove getArea from square class, then Output is:
  Area of Rectangle

  If we also remove getArea from Rectange class, then Output is:
  Area of Shape
  */
}
