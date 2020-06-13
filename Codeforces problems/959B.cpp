#include<bits/stdc++.h>
using namespace std;
main() 
{
  int n,k,m,a;
  string s;
  cin>>n>>k>>m;
  vector<string>v;
  unordered_map<string,int>np;
  for(int i=0;i<n;i++)
  {
    cin>>s;
    v.push_back(s);
    np[s]=i;
  }
  vector<int>p;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    p.push_back(a);
  }
  int x,q;
  unordered_map<int,int>mp;
  for(int i=0;i<k;i++)
  {
    cin>>x;
    vector<int>c;
    int mi=INT_MAX;
    for(int j=0;j<x;j++)
    {
      cin>>q;
      c.push_back(q-1);
      mi=min(mi,p[q-1]);
    }

    for(int j=0;j<x;j++)
    {
      mp[c[j]]=mi;
    }
  }
  int ans=0;
  string r;
  for(int i=0;i<m;i++)
  {
    cin>>r;
    ans+=mp[np[r]];
  }
  cout<<ans<<endl;
  
  return 0;
}
