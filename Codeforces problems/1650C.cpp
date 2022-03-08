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
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>>v;
    for(int i=1;i<=m;i++)
    {
      int x,w;
      cin>>x>>w;
      v.pb({w,x,i});
    }
    sort(v.begin(),v.end());
    vector<pair<int,int>>q;
    int score=0;
    for(int i=0;i<(2*n);i++)
    {
      q.pb({get<1>(v[i]),get<2>(v[i])});
      score+=get<0>(v[i]);
    }
    cout<<score<<endl;

    sort(q.begin(),q.end());

    int sz=2*n;
    for(int i=0, j=sz-1;i<j;i++, j--)
    {
      cout<<q[i].second<<" "<<q[j].second<<endl;
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
    
    
