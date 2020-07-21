#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
main()
{
  io
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,a;
    cin>>n>>m;
    map<int,int>mp;
    int ans,flag=0;
    for(int i=0;i<n;i++){cin>>a;mp[a]++;}
    for(int i=0;i<m;i++)
      {
        cin>>a;
        if(mp[a]){ans=a;flag=1;}
      } 
      if(flag)
      {
        cout<<"YES"<<endl;
        cout<<1<<" "<<ans<<endl;
      } 
      else cout<<"NO"<<endl;
  } 
}
