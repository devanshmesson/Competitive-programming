class Shape
{
  public:
  virtual int getArea()  //Virtual Function
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
  Shape *shp=&sq; //base class shape pointer is pointing to derived class square
  shp->getArea(); //Output : Area of Sqaure


  /*
  If we remove getArea from square class, then Output is:
  Area of Rectangle

  If we also remove getArea from Rectange class, then Output is:
  Area of Shape
  */
}

