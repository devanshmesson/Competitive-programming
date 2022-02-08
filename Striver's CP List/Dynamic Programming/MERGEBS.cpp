// https://www.codechef.com/problems/MERGEBS
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

int n;
int dp[1010][1010];

int choices(string &a,string &b,int i, int j,int one)
{
  if(i>=n && j>=n){return 0;}
  if(dp[i][j]!=-1)return dp[i][j];
  int c1=1e9,c2=1e9;
  if(i<n)
  {
   if(a[i]=='1')c1=choices(a,b,i+1,j,one+1);
   else if(a[i]=='0')c1=one+choices(a,b,i+1,j,one);
  }
  if(j<n)
  {
   if(b[j]=='1')c2=choices(a,b,i,j+1,one+1);
   else if(b[j]=='0')c2=one+choices(a,b,i,j+1,one);  
  }
  return dp[i][j]=min(c1,c2);
}
signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++)dp[i][j]=-1;
    int h=choices(a,b,0,0,0);
    cout<<h<<endl;
  }
}
