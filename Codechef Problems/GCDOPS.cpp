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
    int ans=0,ok=1;
    for(int i=1;i<=n;i++)
      {
        cin>>a[i];
        if(a[i]>i)ok=0;
        if(i%a[i]!=0)ok=0;
      }
    if(ok==0){cout<<"NO"<<endl;continue;}
    else cout<<"YES"<<endl;
  }
}
