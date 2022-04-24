/*
 Change in number of arguments
 Change in type of arguments
*/
class Sum
{
 public:
 int add(int a, int b)
 {
  cout<<"Function 1"<<endl;
  return a+b;
 }
 double add(double a, double b)
 {
  cout<<"Function 2"<<endl;
  return a+b;
 }
 string add(string a, string b)  
 {
  cout<<"Function 3"<<endl;
  return a+b;
 }
 int add(int a, int b, int c)
 {
  cout<<"Function 4"<<endl;
  return a+b+c;
 }
 string add(char ch1, char ch2='M')  //Default argument(2nd one)
 {
   cout<<"Function 5"<<endl;
   string x;
   x+=ch1;
   x+=ch2;
   return x;
 }
};
signed main()
{
  Sum s;
  cout<<s.add(1,2)<<endl;
  cout<<s.add(4.6,10.8)<<endl;
  cout<<s.add(1,2,3)<<endl;
  cout<<s.add("Devansh ","Messon")<<endl;
  cout<<s.add('D')<<endl;
  cout<<s.add('D','C')<<endl;
}
/*
Function 1
3
Function 2
15.4
Function 4
6
Function 3
Devansh Messon
Function 5
DM
Function 5
DC
*/
