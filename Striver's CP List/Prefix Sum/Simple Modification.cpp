//Link - https://www.codechef.com/viewsolution/54051385\
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int diff[1000][1001];
int a[1000][1001];
int init_2d_diff_array(int n,int m)
{
    for(int row=0;row<n;row++)
    {
      diff[row][0]=a[row][0];
      for(int col=1;col<m;col++)
      {
        diff[row][col]=a[row][col]-a[row][col-1];
      }
      diff[row][n]=0;
    }
}
int update(int k,int r1,int c1,int r2,int c2)
{
  for(int i=r1;i<=r2;i++)
  {
    diff[i][c1]+=k;
    diff[i][c2+1]-=k;
  }
}
main()
{
  int n,m,u,q;
  int k,r1,c1,r2,c2;
  cin>>n>>m>>u>>q;
  int prefix[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)cin>>a[i][j];
  }
  init_2d_diff_array(n,m);
  while(u--)
  {
    cin>>k>>r1>>c1>>r2>>c2;
    update(k,r1,c1,r2,c2);
  }

  for(int row=0;row<n;row++)
  {
    for(int col=1;col<m;col++)  
    {
      diff[row][col]=diff[row][col]+diff[row][col-1];
    }
  }
  
  //making 2d prefix sum array
  int sum=0;
  for(int i=0;i<m;i++)
  {
      sum+=diff[0][i];
      prefix[0][i]=sum;
  }
  sum=0;
  for(int i=0;i<n;i++)
  {
      sum+=diff[i][0];
      prefix[i][0]=sum;
  }

  for(int i=1;i<n;i++)
  {
    for(int j=1;j<m;j++)
    {
      prefix[i][j]=prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + diff[i][j];
    }
  }

  while(q--)
  {
    cin>>r1>>c1>>r2>>c2;
    int finalsum= prefix[r2][c2];
    int uppersum=0,leftsum=0,commonsum=0;
    if(r1>0)uppersum=prefix[r1-1][c2];
    if(c1>0)leftsum=prefix[r2][c1-1];
    if(r1>0 && c1>0)commonsum=prefix[r1-1][c1-1];

    //subtracting uppersum and leftsum from finalsum and adding the commonsum
    finalsum=finalsum-uppersum-leftsum+commonsum;
    cout<<finalsum<<endl;
  }
}
