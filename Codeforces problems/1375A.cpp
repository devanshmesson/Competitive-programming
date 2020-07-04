#include<bits/stdc++.h>
using namespace std;
 main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
      if(a[i]==0)cout<<a[i]<<" ";
      else if(i%2==0)cout<<abs(a[i])<<" ";
      else cout<<"-"<<abs(a[i])<<" ";
    }
    cout<<endl;
   }
  return 0;
}
