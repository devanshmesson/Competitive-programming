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
main()
{
  int n,capacity;
  cin>>n;
  capacity=n;
  int value[n+1];
  for(int i=1;i<=n;i++)cin>>value[i];
    int** dp=new int*[n+1];
  for(int i=0;i<=n;i++)dp[i]=new int[capacity+1];

  //base case in recursion = initialisation in Bottom up DP

  //base case:1 if(n==0) return 0;
  for(int i=0;i<=capacity;i++)dp[0][i]=0;

  //base case:2 if(capacity==0)return 0;
  for(int i=0;i<=n;i++)dp[i][0]=0;

  //code the choice diagram

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=capacity;j++)
    {
      if(i<=j) //can include the item
      {
        dp[i][j]=max(value[i]+dp[i][j-i] , dp[i-1][j]); //max(include multiple times , not include)
      }
      else //cannot include the item
      {
        dp[i][j]=dp[i-1][j]; //not include
      }
    }
  }
  cout<<dp[n][capacity]<<endl; //Maximized profit
}
