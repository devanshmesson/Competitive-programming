// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

map<int,int>mp;
int a[200005];
int dp[200005]={0};
set<int>b;
int important;
int help(int upd)
{
  if(upd==0)return 0;
  if(mp[upd]==1)important=upd;
  if(upd %2==1) help((upd-1)/2);
  else if(upd % 4==0)help(upd/4);
  else return 0;
}
const int mod=1e9+7;
signed main()
{
  freopen
  ios
  int n,p;
  cin>>n>>p;
  for(int i=0;i<n;i++){cin>>a[i];mp[a[i]]++;}
  for(int i=0;i<n;i++)
  {
    important=a[i];
    if(a[i]%2==1)help((a[i]-1)/2);
    else if(a[i]%4==0)help(a[i]/4);
    b.insert(important);
  }
  //dp[i] = number of elements in range[2^(i),2(i+1))
  for(auto x: b)
  {
    int exp=log2(x);
    dp[exp]++;
  }
  (dp[1]+=dp[0])%=mod;
  int ans=(dp[1]+dp[0])%mod;
  for(int i=2;i<p;i++)
  {
    int add=(dp[i-1]+dp[i-2])%mod;
    dp[i]=(dp[i]+add)%mod;
    ans=(ans+dp[i])%mod;
  }
  cout<<ans<<endl;
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
