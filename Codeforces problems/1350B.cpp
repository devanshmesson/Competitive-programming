#include<bits/stdc++.h>
using namespace std;

#define pb push_back
int a[100001];
int dp[100001];

int solve(int i,int n,int ans)
{
   ans=1;
   if(i>n)return ans;
   if(dp[i]!=-1)return dp[i];
   for(int j=2*i;j<=n;j+=i)
   {
   if(a[j]>a[i]) ans=max(ans,1+solve(j,n,ans));
   }
   return dp[i]=ans;
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {
   int n,maxi=INT_MIN;
   cin>>n;
   for(int i=1;i<=n;i++){cin>>a[i];dp[i]=-1;}
   int ans;
   for(int i=1;i<=n;i++)maxi=max(solve(i,n,ans),maxi);
   cout<<maxi<<endl;
  }
}
