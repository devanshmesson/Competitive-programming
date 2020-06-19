#include<bits/stdc++.h>

using namespace std;
main()
{
  int n;
  cin>>n;
   
  int i=0,j=0,ans=1;
  vector<pair<int,int>>v;
  v.pb({i,j});

  while(1)
  {
    v.pb({i+1,j});
    v.pb({i,j+1});
    i++;j++;
    v.pb({i,j});
    ans++;
    if(ans-1>n)break;
  }
  cout<<v.size()<<endl;
  for(auto x:v)cout<<x.first<<" "<<x.second<<endl;
 }
