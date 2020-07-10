#include<bits/stdc++.h>
using namespace std;
main() 
{
   int h,w,k;
   cin>>h>>w>>k;
   char v[h+1][w+1];
   int ans=0;
   for(int i=0;i<h;i++)for(int j=0;j<w;j++){cin>>v[i][j];}
   
   for(int i=0;i<(1<<h);i++)
   {
    for(int j=0;j<(1<<w);j++)
    {
      int black=0;
      for(int row=0;row<h;row++)
      {
        for(int col=0;col<w;col++)
        {
          if(((1<<row)&i)==0 && ((1<<col)&j)==0 && v[row][col]=='#')black++;
        }
      }
      if(black==k)ans++;
    }
   }
   cout<<ans<<endl;
  return 0;
}
