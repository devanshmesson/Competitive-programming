/*
Problem-Gven a Nx2 grid,In how many ways we can fill that grid if we have 1x2 and 2x1 rectangles to fill with.
Time Coplexity-O(T*Log(n))
Observation-Last tile left to be filled to completely fill the whole Nx2 grid would be either 1x2 or 2x1.
           -If the last tile is 1x2 ,then obviously the two blocks in other row in the same two columns need to be filled with 1x2.
           They cannot be filled with 2x1.(visualize it).Now we are left with filling remaining (n-2)x2 grid 
           -Now 2^2 grid is filled with two 1x2 tiles.
           Let-
           A-No. of ways to fill (n-2)x
           B-No. of ways to fill 2x(2) which is 1
           Answer for now =A*B
           
           -If the last tile is 2X1,then 2x1 part of the 2xn grid is filled,now we are left with filling remaining (n-1)x2 grid.
           Let-
           C-No. of ways to fill (n-1)x2
           D-No. of ways to fill 2x(1) which is 1
           Final Answer=A*B + C*D
           Where B and D are 1.

Approach-So the answer for nx2 grid is A+C.
        -So,it becomes a fibonacci series starting with
        f(1)=1 - No. of ways to fill 1x2 grid
        f(2)-2 - No. of ways to fill 2x2 grid
        f(3)=f(1)+f(2)
        
        -Popular Method to do it is O(n),but N is very large(10^12) which is very huge for 1 sec.
        -So O(Log N) must be applied to solve the fibonacci series.
        Matrix Expponentiation is the method for computing any reccurrence relation in O(Log N).
        For This Problem- Recurrence Relation is F(n)=F(n-1)+f(n-2)
        
        So our formula would be:
        [f(n)]   = [1 1] ^ n-1 * [f(2)]
        [f(n-1)]   [1 0]         [f(1)]
        
         Let it be:  V              X
        
        Refer this for more explaination- https://youtu.be/EEb6JP3NXBI
                                        - https://youtu.be/d8xB9jgEu-A
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

   for(int i=0;i<2;i++)     //This loop is for Refleccting the changes to the Matrix
   {
    for(int j=0;j<2;j++)
    {
      a[i][j]=res[i][j];
      a[i][j]=a[i][j]%mod;

    }
   }
    
}
void  sol(int n)   //Computing V in LOG(N) and multiplying it with X
{
   int f[2][2]={{1,1},{1,0}};
   int I[2][2]={{1,0},{0,1}};
   int g[2][1]={{2},{1}};   
   ans[0][0]=0;
   ans[1][0]=0;
   n-=2;
   while(n!=0)    //Exact Binary Exponentiation with just a change of replacing base with matrix.(Matrix Exponentiation)
   {
     if(n%2)
     {
       mult(I,f); //=>I=I*f//I is the identity matrix where our answer is stored , f is the base matrix,Our Final I would be V (Refer Approach)
       n--;
     }
     else 
     {
       mult(f,f); //=>f=f*f//mult function is used for multiplying two 2x2 matrices.
       n/=2;
     }
   }
    
   for(int i=0;i<2;i++)   //Multiplying V and X (Refer Approach)
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
  dp[2]=2;
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
