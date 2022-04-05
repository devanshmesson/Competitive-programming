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



signed main()
{
//   freopen
  ios
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    
    vector<int>v[3];
    int mini=INT_MAX;
    vector<pair<int,int>>res;
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<4;j++)
      {
        int a;
        cin>>a;
        v[i].pb(a);
      }
    }
    for(int i=0;i<4;i++)
    {
      mini=INT_MAX;
      for(int j=0;j<3;j++)
      {
        mini=min(mini,v[j][i]);
      }
      res.pb({mini,i});
    }
    int sum=0;
    for(auto x : res)sum+=x.first;
    // cout<<sum-(int)1e6<<endl;
    cout<<"Case #"<<tt<<": ";

    if(sum<(int)1e6)cout<<"IMPOSSIBLE"<<endl;
    else
    {
      int cnt=0;
      sort(res.begin(),res.end());
      int sum=0;
      int ans[4]={0};
      for(int i=0;i<4;i++)
      {
        cnt++;
        sum+=res[i].first;
        if(sum>(int)1e6)
        {
          int del=sum-(int)1e6;
          res[i].first-=del;
          ans[res[i].second]=res[i].first;
          break;
        }
        else ans[res[i].second]=res[i].first;

      }
      for(int i=0;i<4;i++)cout<<ans[i]<<" ";
      cout<<endl;
    }

  }
}


/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 

