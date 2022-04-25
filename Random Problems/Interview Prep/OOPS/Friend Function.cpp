
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

  friend void printArea(Rectangle&); //Declaration of friend function

};

void printArea(Rectangle& rect)  //Friend Function
{
  cout<<"Area of Rectangle is:"<<rect.area<<endl;
}

signed main()
{
  Rectangle rect(8,9);
  rect.getArea();
  //cout<<rect.area<<endl; //This produces error because its private
  printArea(rect);
}
