#include<bits/stdc++.h>
using namespace std;
main()
{ 
  int t;
  cin>>t;
  while(t--)
  {
    int n,ans=0;
    cin>>n;
    int a[n+1],b[n+1];
    vector<int>c;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        if(i>=1)c.pb(a[i]-a[i-1]);
      }
    for(int i=0;i<n;i++)
      {
        cin>>b[i];
        if(i>=1)if(b[i]<=c[i-1])ans++;
      }
    if(b[0]<=a[0])ans++;
    cout<<ans<<endl;
  }
}
