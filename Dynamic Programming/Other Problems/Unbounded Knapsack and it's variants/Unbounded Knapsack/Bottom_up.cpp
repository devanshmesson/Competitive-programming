/*
 Unbounded Knapsack!
 Given 'n' number of items with their weight and value.
 Given a knapsack with a 'capacity'.

 Task-Put items in the knapsack such that profit is maximised keeping in note that
 weight of items must not exceed capacity of knapsack.Particular item can be put in the knapsack
 any number of times(infinite quantity).

 Example-
 n=8
 weight array-1 2 3 4  5  6  7  8
 value  array-1 5 8 9 10 17 17 20

 Maximum Profit=22

item : quantity
  6  : 1    =17
  2  : 1    =5
  ------------
            =22
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int weight[n+1],val[n+1];
  for(int i=1;i<=n;i++)cin>>weight[i];
  for(int i=1;i<=n;i++)cin>>val[i];
  int capacity;
  cin>>capacity;
 
  /*
   Item can be put multiple times in knapsack;

   if : item is to be put one more time - dont traverse the array,stay on that index
   if : item is not to be put in knapsack - traverse the array further,go to next index

   do the same until we traversed whole array
  */

  //to solve using dp, build a matrix
  int** dp=new int*[capacity+1];
  for(int row=0;row<=capacity;row++)dp[row]=new int[n+1];

  //base case in recursion = initialisation in dp

  //base case:1 if capacity==0 , return 0
  for(int i=0;i<=n;i++)dp[0][i]=0;

  //base case:2 if n==0 ,return 0
   for(int i=0;i<=capacity;i++)dp[i][0]=0;

  //Simply code the choice diagram

  for(int i=1;i<=capacity;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(weight[j]<=i) //Case:1
      {
        dp[i][j]=max(val[j]+dp[i-weight[j]][j] //include the item 1 or more times,stay on that index
                           ,dp[i][j-1]);       //skip this item,move to next index
      }
      else //Case:2
      {
        dp[i][j]=dp[i][j-1];
      }
    }
  }

  cout<<dp[capacity][n]<<endl;
  
  return 0;
}
