#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
   int n,m,x,y,a,b,sum=0;
   cin>>n>>m>>x>>y;
   int ans[n+1][m+1]={0};
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
      ans[i][j]=0;
    }
   }
   int nn=n;

   if(x>y)
   {
    a=y;
   }
   else
    {
      a=x;
    }
    if(n==1 && m==1)a=x;
   
 ans[0][0]=a;
 sum+=ans[0][0];
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<m;j++)
  {
     if(i==0 && j==0)continue;
     int mn=INT_MAX,req;
  if(i-1>=0 && j>=0 && i-1<n && j<m)
  {
    req=y-ans[i-1][j];
     if(req>x)req=x;
    mn=min(mn,req);
  }
  if(i+1>=0 && j>=0 && i+1<n && j<m)
  {
    req=y-ans[i+1][j];
    if(req>x)req=x;
    mn=min(mn,req);
  }
  if(i>=0 && j-1>=0 && i<n && j-1<m)
  {
    req=y-ans[i][j-1];
     if(req>x)req=x;
    mn=min(mn,req);
  }
  if(i>=0 && j+1>=0 && i<n && j+1<m)
  {
    req=y-ans[i][j+1];
    if(req>x)req=x;
    mn=min(mn,req);
  }
  ans[i][j]=mn;
  sum+=ans[i][j];
  }
 }
 cout<<sum<<endl; 
  }
}
