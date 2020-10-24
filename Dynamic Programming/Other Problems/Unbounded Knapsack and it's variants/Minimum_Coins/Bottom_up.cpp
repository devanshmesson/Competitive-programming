/*
Problem-Given a set of coins and a target sum.
Task-Find Minimum number of coins required to achive the required sum.
 This problem boils down to minimizing cost of adding item to knapsack.
 
 Cost of including every item=1.
 Capacity of knapsack=Target sum.
 weight array = set of coins.
 
 so,answer=min(include the item multiple times , not include the item)
 
 FILL THE KNAPSACK EQUAL TO THE CAPACITY.
 
*/

#include<bits/stdc++.h>
using namespace std; 
int main()
{
  int n,sum;
  cin>>n;
  int coins[n+1];
  cin>>sum;
  for(int i=1;i<=n;i++)cin>>coins[i];
  
  int** dp=new int*[n+1];
  for(int i=0;i<=n;i++)dp[i]=new int[sum+1];

  //Base Case in recursion = Initialization in Bottom up

  //Base Case:1 if(sum==0)return 0;
  for(int i=0;i<=n;i++)dp[i][0]=0;

  //Base Case:2 if(n==0 && sum!=0)return 1e9;
  for(int i=1;i<=sum;i++)dp[0][i]=1e9;

  //code the choice diagram
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(coins[i]<=j)
      {
        dp[i][j]=min(1+dp[i][j-coins[i]] , dp[i-1][j]);
        
      /*
     2 ways to achieve the sum.
    
     Take minimum of answer of the 2 ways:
     way 1:include the item multiple items.
     way 2:not include the item.
     
     while including the item add 1 to the function call. '1' signifies that coin is included.
     while not including the item add nothing to the function call. 'Nothing' signifies that coin is not included.
     
     */
     
      }
      else
      {
        dp[i][j]=dp[i-1][j];
      }
    }
  }

  if(dp[n][sum]==1e9)cout<<-1<<endl;
  else cout<<dp[n][sum]<<endl;
}
