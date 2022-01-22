//Link - https://codeforces.com/contest/486/problem/B
#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define int long long int
#define pb push_back
main()
{
  int m,n;
  cin>>m>>n;
  int b[m][n],zerorow[m],zerocol[n];
  for(int i=0;i<m;i++)zerorow[i]=1;
  for(int i=0;i<n;i++)zerocol[i]=1;

  int ans[m][n];
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      ans[i][j]=1;
    }
  }
  
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>b[i][j];
      if(b[i][j]==0){zerorow[i]=0;zerocol[j]=0;}
    }
  }


  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(zerocol[j]==0 || zerorow[i]==0)ans[i][j]=0;
    }
    
  }

  bool ok=1;
  bool flag=0;
  for(int i=0;i<m;i++)
  {
    ok=1;
    flag=0;
    for(int j=0;j<n;j++)
    {
      flag=0;
      for(int k=0;k<n;k++)if(ans[i][k]==1){flag=1;break;}
      for(int k=0;k<m;k++)if(ans[k][j]==1){flag=1;break;}
      if(flag==0 && b[i][j]==1){ok=0;break;}
      if(flag==1 && b[i][j]==0){ok=0;break;}
    }
    if(ok==0)break;
  }
 
  if(ok==0){cout<<"NO"<<endl;return 0;}
  cout<<"YES"<<endl;
 
   for(int i=0;i<m;i++)
   {
    for(int j=0;j<n;j++)
    {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
}
