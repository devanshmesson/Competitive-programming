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
int steps[1001];

int knapsack(int n,int cap,int *b, int *c,vector<vector<int>>&dp)
{
  if(n<0 || cap<0)return 0;
  if(dp[n][cap]!=-1)return dp[n][cap];
  if(b[n]<=cap)
  {
    int take=c[n]+knapsack(n-1,cap-b[n],b,c,dp);
    int donttake=knapsack(n-1,cap,b,c,dp);
    return dp[n][cap]=max(take,donttake);
  }
  else
  {
    int donttake=knapsack(n-1,cap,b,c,dp);
    return dp[n][cap]=donttake;
  }
}
signed main()
{
  freopen
  ios
  int a[1001];
  for(int i=1;i<=1000;i++)steps[i]=1000;
  steps[1]=0;
  for(int i=1;i<=1000;i++)
  {
    for(int j=1;j<=(i/2)+1;j++)
    {
      int go=i+(i/j);
      if(go<=1000)steps[go]=min(steps[go],steps[i]+1);
    }
  }
  int t;
  cin>>t;
  int maxcapneed=12000;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int b[n],c[n];
    int sum=0;
    for(int i=0;i<n;i++){cin>>b[i];b[i]=steps[b[i]];}
    for(int i=0;i<n;i++){cin>>c[i];sum+=c[i];}
    if(k>=maxcapneed){cout<<sum<<endl;continue;}
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    cout<<knapsack(n-1,k,b,c,dp)<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
    */ 
    
    
    
    
    
