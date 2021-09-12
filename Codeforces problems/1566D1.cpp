#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
#define int long long int

bool comp(const pair<int,int>&a, const pair<int,int>&b)
{
   if(a.first==b.first && a.second > b.second )return a.second > b.second; 
   return a.first<b.first;
}
main()
{
//   freopen
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    unordered_map<int,int>mp;
    int a[m+1];
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++)
      {
        cin>>a[i];
        v.push_back({a[i],i+1});
      }
    sort(v.begin(),v.end());
    
    for(int i=0;i<m;i++)
    {
      // cout<<v[i].first<<" "<<v[i].second<<endl;
      int x=v[i].second;
      mp[x]=i;
    }

    int ans=0;
    for(int i=2;i<=m;i++)
    {
      for(int j=i-1;j>=1;j--)
      {
        if(mp[i] > mp[j] && v[mp[i]].first!=v[mp[j]].first)ans++;
      }
    }

   // cout<<ans<<endl;

    cout<<ans<<endl;
    

  }
}
