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
const int mod=1e9+7; // without const keyword , TLE Comes. 
 
int dp[110][1000010];
 
int coinchange1(int coin[],int n,int sum)
{
  
  //if already computed
  if(dp[n][sum]!=-1)return dp[n][sum]%mod;
 
  //base condition
  if(sum==0)return 1;
  if(n==0 && sum!=0)return 0;
 
  //choice diagram
  if(coin[n]<=sum)
  {
    return (dp[n][sum]=(coinchange1(coin,n,sum-coin[n])%mod + coinchange1(coin,n-1,sum)%mod))%=mod;
  }
  else
  {
    return dp[n][sum]=coinchange1(coin,n-1,sum)%mod;
  }
}
 
int main()
{
  int n,sum;
  cin>>n;
  int coin[n+1];
  cin>>sum;
  for(int i=1;i<=n;i++)cin>>coin[i];
 
  for(int i=0;i<=n;i++)
  for(int j=0;j<=sum;j++)
  dp[i][j]=-1;
 
  cout<<coinchange1(coin,n,sum)%mod;
}
