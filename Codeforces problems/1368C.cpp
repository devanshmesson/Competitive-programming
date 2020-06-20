#include<bits/stdc++.h>
using namespace std;
main()
{
  int n;
  cin>>n;
  vector<pair<int,int>>v;
  int i=0,j=0,ans=0;
  v.pb({i,j});
  while(1)
  {
    v.pb({i+1,j});
    v.pb({i,j+1});
    i++;j++;
    if(i>=2)ans++;
    v.pb({i,j});
    if(ans==n)break;            
  }
  cout<<v.size()<<endl;
  for(auto x:v)cout<<x.first<<" "<<x.second<<endl;
 }
