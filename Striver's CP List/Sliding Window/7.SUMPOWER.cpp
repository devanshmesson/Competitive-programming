//Link - https://www.codechef.com/problems/SUMPOWER
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

signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=-1,sum=0;
    for(int i=0;i<k;i++)sum+=(s[i]!=s[i+1]);
    ans=sum;
    for(int i=k;i<n-1;i++)
    {
     sum-=(s[i-k]!=s[i-k+1]);
     sum+=(s[i]!=s[i+1]);
     ans+=sum;
    }
    cout<<ans<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
    */ 
