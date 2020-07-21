
#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
main()
{
  io
  int t;
  cin>>t;
  while(t--)
  {
    int n,ans=-1;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i]; 
    for(int i=0;i<n;i++)if(a[i]>1){ans=i;break;}
    if(ans==-1)
    {
      if(n%2==0)cout<<"Second"<<endl;
      else cout<<"First"<<endl;
      continue;
    }
    if(ans%2==0)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
  }
}
