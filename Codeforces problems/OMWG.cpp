//Approach-Colour the cells row by row 
#include<bits/stdc++.h>
using namespace std;
int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int n,m;
    cin>>n>>m;
    int a[n][m]={0};
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)a[i][j]=0;

    auto check=[&](int x,int y)
    {
      if(x>=0 && y>=0 && x<n && y<m)return 1;
      else return 0;
    };
    a[0][0]=1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        ans+=check(i-1,j)?(a[i-1][j]==1):0;
        ans+=check(i+1,j)?(a[i+1][j]==1):0;
        ans+=check(i,j+1)?(a[i][j+1]==1):0;
        ans+=check(i,j-1)?(a[i][j-1]==1):0;
        a[i][j]=1;
      }
    }
    cout<<ans<<endl;
   }
}
