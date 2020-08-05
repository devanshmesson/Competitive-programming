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
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    sort(a,a+n);
    int ok=0;
    for(int i=0;i<n-1;i++)
    {
      if(abs(a[i]-a[i+1])>1)ok=1;
    }
    if(ok==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
