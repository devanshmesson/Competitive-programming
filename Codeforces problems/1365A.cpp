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
    int a[n+1][m+1];
    map<int,int>r,c;

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        cin>>a[i][j];
        if(a[i][j]==1)
         { r[i]=1;
           c[j]=1;
         }
      }
    }
    int cnt=0;

    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
      { 
          if(r[i]==0 && c[j]==0 )
            {
              cnt++; r[i]=1; c[j]=1;
            }
          }
       }
    if(cnt%2==0)cout<<"Vivek"<<endl;
    else cout<<"Ashish"<<endl;
   }
}
