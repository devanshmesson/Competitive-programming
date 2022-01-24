#include<bits/stdc++.h>
using namespace std;
#define pb push_back

signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    vector<pair<int,int>>v;
    int n=s.size();
    for(int i=1;i*i<=n;i++)v.pb({i*i,i});
    int sz=v.size();
    int one=0,zero=0;
    int prefixone[n+1],prefixzero[n+1];
    
    //precomputation - prefix sum
    for(int i=0;i<n;i++)
    {
      if(s[i]=='0')zero++;
      else one++;
      prefixone[i]=one;
      prefixzero[i]=zero;
    }

    //Sliding window
    one=0;
    zero=0;
    int ans=0;
    for(int k=0;k<sz;k++)
    {
      int window=v[k].first+v[k].second;
      one=prefixone[window-1];
      zero=prefixzero[window-1];
      if(zero==one*one)ans++;
      for(int i=window;i<n;i++)
      {

        one=prefixone[i]-prefixone[i-window]; 
        zero=prefixzero[i]-prefixzero[i-window]; 
        if(zero==one*one)ans++;
      }
    }
    cout<<ans<<endl;

  }
  
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
*/ 
