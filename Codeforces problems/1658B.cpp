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

const int mod=998244353;
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
    if(n%2==1){cout<<0<<endl; continue;}
    n/=2;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
      ans=(ans*i)%mod;
    }
    ans=(ans*ans)%mod;
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
    
    
