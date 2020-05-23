#include<bits/stdc++.h>
using namespace std;

#define int long long int
 
main() 
{ 
  int n;
  cin>>n;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  int ans=INT_MIN,sum=0;
  for(int i=0;i<n;i++)
    {
      sum=max(a[i],sum+a[i]);
      ans=max(ans,sum);
    }
    cout<<ans<<endl;
 }
