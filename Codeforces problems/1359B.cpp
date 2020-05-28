#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
 {   
   int n,m,x,y;
   cin>>n>>m>>x>>y;
   char a[n+1][m+1];
   int cnt=0;
   int x1,y1;
   int ans=0;
   for (int i = 0; i < n; ++i)
   {
     for(int j=0;j<m;j++)
     {
       cin>>a[i][j];
     }
   }
   bool flag=0;
   for (int i=0;i<n;i++)
   {
     cnt=0;
     for(int j=0;j<m;j++)
     {
        if(a[i][j]!='*'){flag=0;cnt++;}
        else 
        {
         flag=1;
        if(cnt%2==0)
        {
          x1=(cnt/2)*y;
        }
        else 
        {
          x1=(cnt/2)*y+x;
        }
        y1=cnt*x;
        ans+=min(y1,x1);
        cnt=0;

        }
     }

     if(flag==0 && cnt>0)
     {
        if(cnt%2==0)
        {
          x1=(cnt/2)*y;
        }
        else 
        {
          x1=(cnt/2)*y+x;
        }
        y1=cnt*x;
        ans+=min(y1,x1);
        cnt=0;
     }
    
   }

cout<<ans<<endl;

   
 }
}
