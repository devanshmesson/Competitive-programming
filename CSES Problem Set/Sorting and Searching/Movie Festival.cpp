#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>&a,pair<int,int>&b)
{
  return a.second<b.second;
}
 
main() 
{ 
 int n,a,b,upd=0;
 cin>>n;
 vector<pair<int,int>>v;
 for(int i=0;i<n;i++)
 {
  cin>>a>>b;
  v.push_back({a,b});
 }

 sort(v.begin(),v.end(),comp);
int ans=1;
 for(int i=1;i<n;i++)
 {
  if(v[i].first>=v[upd].second)
    {
      ans++;
      upd=i;
    }
 }
 cout<<ans<<endl;
 }
