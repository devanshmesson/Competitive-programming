#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    char a[n+1][m+1];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    int ans=0;
    for(int i=0;i<m-1;i++)
    {
      if(a[n-1][i]!='R')ans++;
    }
    for(int i=0;i<n-1;i++)
    {
      if(a[i][m-1]!='D')ans++;
    }
    cout<<ans<<endl;
  }
}
