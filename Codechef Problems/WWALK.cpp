#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x,sum=0;
    cin>>n;
    int a[n+10];
    int b[n+10];
    int c[n+10];
    int d[n+10];
    a[0]=0;b[0]=0;

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        sum+=c[i];
        a[i]=sum;
    }
    sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        sum+=d[i];
        b[i]=sum;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
       if(c[i]==d[i] && a[i]==b[i])ans+=c[i];
    }
    cout<<ans<<endl;
    
  }
}
