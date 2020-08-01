#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x,ans;
    cin>>n>>x;
    int a[n+1];
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      mp[a[i]]++;
    }
    for(int i=1;x;i++)
    {
      if(mp[i])continue;
      else x--;
      mp[i]++;
    }
    int i=1;
    while(1)
    {
      if(mp[i]==0){ans=i;break;}
      i++;
    }
    cout<<ans-1<<endl;  
    }  
}
