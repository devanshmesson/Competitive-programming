/*
 Problem-Coordinates of Rectangles are given, Find the Missing Point.
 Approach-Solved by using XOR
 Observation-if we Xor elements who have even number of occurrence then resulting xor is 0.
            -for example-Xor(4,4,9,9)=0
                        -if we XOR(4,4,9)=9
                        -To make it equal to 0 we will Xor it with 9
                        ->9^9=0
Method-Xor all x coordinates , this is the answer for x coordinate 
      -Xor all y coordinates , this is the answer for y coordinate 
*/
#include<bits/stdc++.h>
using namespace std;
main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,a,b,x=0,y=0;
  cin>>n;
  for(int i=0;i<(4*n)-1;i++)
  {
    cin>>a>>b;
    x^=a;
    y^=b;
  }
  cout<<x<<" "<<y<<endl;
 }
}
