#include<bits/stdc++.h>
using namespace std;
main() 
{
   int t;
   cin>>t;
   while(t--)
   {
   int n,m,ok=1;
   cin>>n>>m;
   int a[n+10][m+10];
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
      int limit=0;
      if(i>0)limit++;
      if(i<n-1)limit++;
      if(j>0)limit++;
      if(j<m-1)limit++;
      cin>>a[i][j];
      if(a[i][j]>limit)ok=0;
    }
   }
   if(!ok){cout<<"NO"<<endl;continue;}
   cout<<"YES"<<endl;
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
      int limit=0;
      if(i>0)limit++;
      if(i<n-1)limit++;
      if(j>0)limit++;
      if(j<m-1)limit++;
      cout<<limit<<" ";
    }
    cout<<endl;
   }
  }
  return 0;
}
