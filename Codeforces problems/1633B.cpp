// taskkill /IM "a.exe" /F
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
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int one=0,zero=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
      one+=(s[i]=='1');
      zero+=(s[i]=='0');
    }
    if(one==zero)cout<<one-1<<endl;
    else cout<<min(one,zero)<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
    */ 
