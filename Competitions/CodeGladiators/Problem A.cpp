#include<bits/stdc++.h>
using namespace std;
main()
{
  int n,x,ans=INT_MAX;
  cin>>n;
  
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];

  for(int i=0;i<n;i++)
  {
    cin>>x;
    ans=min(ans,x/a[i]);
  }
 cout<<ans<<endl;
 }
