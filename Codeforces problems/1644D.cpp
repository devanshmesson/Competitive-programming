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
int power(int b, int e)
{
  int a=1;
  while(e>0)
  {
    if(e%2==0)
    {
      e/=2;
      b=(b*b)%mod;
    }
    else
    {
      e--;
      a=(a*b)%mod;
    }
  }
  return a;
}
signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    set<int>rows,cols;
    vector<pair<int,int>>v;
    for(int i=0;i<q;i++)
    {
      int r,c;
      cin>>r>>c;
      v.pb({r,c});
    }
    int ans=0;
    for(int i=q-1;i>=0;i--)
    {
      int rowfill=rows.count(v[i].first);
      int colfill=cols.count(v[i].second);
      if(rowfill==1 && colfill==1)continue;
      if(rows.size()==n || cols.size()==m)continue;
      if(rows.size()!=n || cols.size()!=m)ans++;

      rows.insert(v[i].first);
      cols.insert(v[i].second);
    }
    int res=power(k,ans);
    cout<<res<<endl;
  }
 
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
