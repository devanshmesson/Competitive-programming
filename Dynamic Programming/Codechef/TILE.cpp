/*
Problem-Gven a Nx2 grid,In how many ways we can fill that grid if we have 1x2 and 2x1 rectangles to fill with.
Time Coplexity-O(T*Log(n))
Observation-Last tile left to be filled to completely fill the whole Nx2 grid would be either 1x2 or 2x1.
           -If the last tile is 1x2 ,then obviously the two blocks in other row in the same two columns need to be filled with 1x2.
           They cannot be filled with 2x1.(visualize it).Now we are left with filling remaining 2x(n-2) grid 
           -Now 2^2 grid is filled with two 1x2 tiles.
           Let-
           A-No. of ways to fill 2x(n-2)
           B-No. of ways to fill 2x(2) which is 1
           Answer for now =A*B
           
           -If the last tile is 2X1,then 2x1 part of the 2xn grid is filled,now we are left with filling remaining 2x(n-1) grid.
           Let-
           C-No. of ways to fill 2x(n-1)
           D-No. of ways to fill 2x(1) which is 1
           Final Answer=A*B + C*D
           Where B and D are 1.

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int ans[2][2];
int mod=1000000007;
void mult(int a[2][2] , int b[2][2])
{
   int res[2][2]={{0,0},{0,0}};
   for(int i=0;i<2;i++)
   {
    for(int j=0;j<2;j++)
    {
      for(int k=0;k<2;k++)
      {
         res[i][j]+=(a[i][k]*b[k][j])%mod;
         res[i][j]=res[i][j]%mod;
      }
    }
   }

   for(int i=0;i<2;i++)
   {
    for(int j=0;j<2;j++)
    {
      a[i][j]=res[i][j];
      a[i][j]=a[i][j]%mod;

    }
   }
    
}
void  sol(int n)
{
   int f[2][2]={{1,1},{1,0}};
   int I[2][2]={{1,0},{0,1}};
   int g[2][1]={{1},{1}};
   ans[0][0]=0;
   ans[1][0]=0;
   n-=2;
   while(n!=0)
   {
     if(n%2)
     {
       mult(I,f);
       n--;
     }
     else 
     {
       mult(f,f);
       n/=2;
     }
   }
    
   for(int i=0;i<2;i++)
   {
    for(int j=0;j<1;j++)
    {
       for(int k=0;k<2;k++)
       {
         ans[i][j]+=(I[i][k]*g[k][j])%mod;
         ans[i][j]=ans[i][j]%mod;
       }

    }
   }
}

main()
{
  map<int,int>dp;
  dp[1]=1;
  dp[2]=1;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    if(dp[n]!=0){cout<<dp[n]<<endl;continue;}
    sol(n);
    dp[n]=ans[0][0];
    cout<<dp[n]<<endl;
  }
}
