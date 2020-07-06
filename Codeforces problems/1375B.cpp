#include<bits/stdc++.h>
using namespace std;

int a[301][301],n,m;
vector<int> check(int i,int j)
{
  int yes=0,yep=0;
  vector<int>ans;
  if(i-1>=0 && i-1<n && j>=0 && j<m){yes++;if(a[i-1][j]>0)yep++;}
  if(i+1>=0 && i+1<n && j>=0 && j<m){yes++;if(a[i+1][j]>0)yep++;}
  if(i>=0 && i<n && j-1>=0 && j-1<m){yes++;if(a[i][j-1]>0)yep++;}
  if(i>=0 && i<n && j+1>=0 && j+1<m){yes++;if(a[i][j+1]>0)yep++;}
  ans.pb(yes);
  ans.pb(yep);
  return ans;
}

void imple(int i,int j,int stop)
{
  vector<int>ans;
  if(i-1>=0 && i-1<n && j>=0 && j<m && stop>0)
    {
      if(a[i-1][j]>0)stop--;
      else {a[i-1][j]++;stop--;}
    }
  if(i+1>=0 && i+1<n && j>=0 && j<m && stop>0)
    {
      if(a[i+1][j]>0)stop--;
      else {a[i+1][j]++;stop--;}
    }
  if(i>=0 && i<n && j-1>=0 && j-1<m && stop>0)
    {
      if(a[i][j-1]>0)stop--;
      else {a[i][j-1]++;}
    }
  if(i>=0 && i<n && j+1>=0 && j+1<m && stop>0)
    {
      if(a[i][j+1]>0)stop--;
      else {a[i][j+1]++; stop--;}
    }
}   
main() 
{
   int t;
   cin>>t;
   while(t--)
   {
     int ok=1;
     cin>>n>>m;
     vector<int>rec;
     for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>a[i][j];rec=check(i,j);if(a[i][j]>rec[0])ok=0;}
     if(ok==0){cout<<"NO"<<endl;continue;}
     cout<<"YES"<<endl;
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<m;j++)
      {
        vector<int>chk;
        chk=check(i,j);
        if(a[i][j]<=chk[0] && a[i][j]>0)
        {
           if(a[i][j]>chk[1])
           {
             imple(i,j,a[i][j]);
           }
           else if(a[i][j]<chk[1])a[i][j]+=(chk[1]-a[i][j]);
        }
      }
     }
      for(int i=0;i<n;i++)
     {
      for(int j=0;j<m;j++)
      {
        vector<int>chk;
        chk=check(i,j);
        if(a[i][j]<=chk[0] && a[i][j]>0)
        {
           if(a[i][j]>chk[1])
           {
             imple(i,j,a[i][j]);
           }
           else if(a[i][j]<chk[1])a[i][j]+=(chk[1]-a[i][j]);
        }
      }
     }
     for(int i=0;i<n;i++)
     {
       for(int j=0;j<m;j++)
       {
         cout<<a[i][j]<<" ";
       }
       cout<<endl;
     }
   }
  return 0;
}
