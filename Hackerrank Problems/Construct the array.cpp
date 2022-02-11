//Link - https://www.hackerrank.com/challenges/construct-the-array/problem?isFullScreen=false
const long long int mod=1e9+7;
long countArray(int n, int k, int x) 
{
   long long  int dp[n+1][2];
  dp[1][0]=(x!=1);
  dp[1][1]=(x==1);

  for(int i=2;i<n;i++)
  {
    dp[i][0]=((dp[i-1][1]*(k-1))%mod + (dp[i-1][0]*(k-2))%mod)%mod;
    dp[i][1]=dp[i-1][0]; 
  }
  return dp[n-1][0];
}
