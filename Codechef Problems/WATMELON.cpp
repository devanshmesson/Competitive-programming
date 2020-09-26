#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    int ans=0;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        if(i>=1)ans+=a[i];
      }
    if(n==1)
    {
      if(a[0]<0)cout<<"NO"<<endl;
      else cout<<"YES"<<endl;
    }
    else if(n>=2)
    {
      a[1]=ans;
      if(a[0]>=0 && a[1]>=0)cout<<"YES"<<endl;
      else if(a[0]<=0 && a[1]>=0 && a[1]>=abs(a[0]))cout<<"YES"<<endl;
      else if(a[0]>=0 && a[1]<=0 && a[0]>=abs(a[1]))cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
}
