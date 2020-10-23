/*
 Rod Cutting Problem
 Unbounded Knapsack!
 Given a Rod of length 'n'.Rod can be cut in pieces of length from 1 to n.
 Each piece has a certain value.
 
 Task- Cut the rod in such a way so that if we add the value of all pieces the result is maximum.
 
 Example-
 n=8
 value  array-1 5 8 9 10 17 17 20 (index(1-based) of  the value array corresponds to the length of the piece)

 Maximum Profit=22

item : quantity
  6  : 1    =17
  2  : 1    =5
  ------------
            =22
*/
#include<bits/stdc++.h>
using namespace std;

int rodcut(int value[],int n,int capacity)
{
  //base condition
  if(n==0 || capacity==0){return 0;}

  //code the choice diagram
  if(n<=capacity) //can include the item
  {
    return max(value[n]+rodcut(value,n,capacity-n) , rodcut(value,n-1,capacity) ); //max(include multiple times , not include) 
  }
  else //cannot inclide the item
  {
    return answer=rodcut(value,n-1,capacity); //never include the item
  }
}
main()
{
  int n,capacity;
  cin>>n;
  capacity=n;
  int value[n+1];
  for(int i=1;i<=n;i++)cin>>value[i];
  
  cout<<rodcut(value,n,capacity)<<endl;
}
