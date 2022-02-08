//Link - https://www.codechef.com/problems/GOODBINTREE
#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
#define int long long int


const int mod=1000000007;

signed main()
{
//   freopen
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
     if(n==1)
    {
      cout<<m<<endl;
      continue;
    }
    int h=log(n+1)/log(2);
    // cout<<h<<endl;
    int dp[h+1][m+1];
    int prefix[h+1][m+1];
    for(int i=0;i<=h;i++)
    {
        for(int j=0;j<=m;j++)prefix[i][j]=0;
    }
    int sum=0;
    for(int i=1;i<=m;i++)
      {
        dp[1][i]=1;
        sum+=dp[1][i];
        prefix[1][i]=sum;
      }


    for(int i=2;i<=h;i++)
    {
      sum=0;
      for(int j=1;j<=m;j++)
      {
        int parity=h-i+1;
        if(parity%2==1) //it's children are at even level
        {
          int ways=(prefix[i-1][m]%mod-prefix[i-1][j]%mod)%mod;
          dp[i][j]=(ways*ways)%mod;
        }
        else  //it's children are at odd level
        {
         int ways=(prefix[i-1][j-1]%mod-prefix[i-1][0]%mod)%mod;
         dp[i][j]=(ways*ways)%mod;
        }
        (sum+=dp[i][j])%=mod;
        prefix[i][j]=sum;
      }
    }
    cout<<prefix[h][m]%mod<<endl;
  }
}
