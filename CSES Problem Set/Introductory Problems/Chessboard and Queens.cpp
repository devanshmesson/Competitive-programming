#include<bits/stdc++.h>

#define int long long int
 
int left[100],rit[100],col[100],ans=0;
char a[10][10];
 
int ways(int x,int res[][100])
{
  if(x==9){ans++;}
  for(int y=1;y<=8;y++)
  {
    if(res[x][y])continue;
    if(col[y] || left[x+y] || rit[y-x+8])continue;
    col[y]=left[x+y]=rit[y-x+8]=1;
    ways(x+1,res);
    col[y]=left[x+y]=rit[y-x+8]=0;
  }
  return ans;
}
 
int32_t main()
{
  int res[100][100]={0};
  for(int i=1;i<=8;i++)
  {
    for(int j=1;j<=8;j++)
    {
       std::cin>>a[i][j];
      if(a[i][j]=='*'){res[i][j]=1;}
    }
  }
  std::cout<<ways(1,res);
 
} 
