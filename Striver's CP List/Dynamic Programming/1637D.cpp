// https://codeforces.com/contest/1637/problem/D
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double
 

const int M=101;
int dp[M][M*M];

signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    int totalsum=0;
    int squaresum=0;
    int s1=0,s2=0;
    for(int i=0;i<n;i++){cin>>a[i];s1+=a[i];squaresum+=a[i]*a[i];}
    for(int i=0;i<n;i++){cin>>b[i];s2+=b[i];squaresum+=b[i]*b[i];}
    if(n==1){cout<<0<<endl;continue;}
    totalsum=s1+s2;
    

    for(int i=0;i<n;i++)for(int sum=0;sum<=totalsum;sum++)dp[i][sum]=0;
    dp[0][a[0]]=1;
    dp[0][b[0]]=1;
    

    
    int minsum=INT_MAX;
    for(int i=1;i<n;i++)
    {
      for(int sum=1;sum<=totalsum;sum++)
      {
        if(sum>=a[i])
        {
          dp[i][sum]=dp[i-1][sum-a[i]];
        }
        if(sum>=b[i])
        {
          dp[i][sum]|=dp[i-1][sum-b[i]];
        }
        if(i==n-1 && dp[i][sum]==1)
        {
          int d2=totalsum-sum;
          d2*=d2;
          int d1=sum*sum;
          minsum=min(minsum,d1+d2);
        }
      }
    }
    
    int ans=((n-2)*squaresum)+minsum;
    cout<<ans<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
