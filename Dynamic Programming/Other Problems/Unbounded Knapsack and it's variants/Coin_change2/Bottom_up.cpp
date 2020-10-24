/*
Problem-Given a set of coins with infinite quantity.
Task-Find number of distinct ordered ways of using these coins which sum up to a given "Target sum".
For ex:
n=3 sum=5
coins->2 3 5
Output-2 [2+3] [5]
2+3 and 3+2 must be counted as 1.
*/

#include<bits/stdc++.h>
using namespace std;
 
const int mod=1e9+7;
int main()
{
  int n,sum;
  cin>>n;
  int coin[n+1];
  cin>>sum;
  for(int i=1;i<=n;i++)cin>>coin[i];
  
  int dp[n+10][sum+10];
 
 
  //base case in recusrion =  initialisation in bottom up DP
  
  //base case:1 if(sum==0)return 1
  for(int i=0;i<=n;i++)dp[i][0]=1;
 
  //base case:2 if(n==0 && sum!=0)return 0;
  for(int i=1;i<=sum;i++)dp[0][i]=0;
 
  //code the choice diagram
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(coin[i]<=j)
      {
        dp[i][j]=dp[i][j-coin[i]]%mod +  dp[i-1][j]%mod;
        dp[i][j]%=mod;
      }
      else
      {
        dp[i][j]=dp[i-1][j]%mod;
      }
    }
  }
 
  cout<<dp[n][sum]%mod;
}
