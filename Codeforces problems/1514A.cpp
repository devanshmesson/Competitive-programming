#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define pb push_back
 
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    int flag=0;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        int sq=sqrt(a[i]);
        if(sq*sq!=a[i])flag=1;
      }

      if(flag==1)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
  }
}
