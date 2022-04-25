class Rectangle
{
  
  private:
  int length, breadth, area;
  public:
  int getArea()
  {
    area=length*breadth;
  }
  Rectangle(int length,int breadth)
  {
    (*this).length=length;
    this->breadth=breadth;
  }

  friend class FriendRectangle;  //frienc class

};
class Derived:public Rectangle //Just for demonstrating that frindship is not inheritable.
{
  int x;
  public:
  Derived(): Rectangle{1,2} {} 
};

class FriendRectangle  //Freind class
{
 public:
 Derived b;
 void printArea(Rectangle& rect)  
 {
  cout<<"Area of Rectangle is:"<<rect.area<<endl;
  //b.x;  //Friend class of Rectange, which is 'A', is not a frind class of derived class of Rectangle.
 }
};


signed main()
{
  Rectangle rect(8,9);
  rect.getArea();
  //cout<<rect.area<<endl; //This produces error because its private
  FriendRectangle f;
  f.printArea(rect);
}
