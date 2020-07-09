#include<bits/stdc++.h>
using namespace std;
main() 
{
   int h,w,k;
   cin>>h>>w>>k;
   char v[h+1][w+1];
   int tot=0;
   for(int i=0;i<h;i++)for(int j=0;j<w;j++){cin>>v[i][j];if(v[i][j]=='#')tot++;}
   int black=tot,ans=0;
   for(int a=0;a<(1<<h);a++)
   {
    for(int b=0;b<(1<<w);b++)
    {
      bitset<6>x(a);
      bitset<6>y(b);
      map<pair<int,int>,int>chk;
      black=tot;

      for(int i=0;i<6;i++)
      {
        if(x[i])
        {
          for(int j=0;j<w;j++)
          {
            if(v[i][j]=='#' && chk[{i,j}]==0){chk[{i,j}]++;black--;}
          }
        }
      }
      for(int i=0;i<6;i++)
      {
        if(y[i])
        {
          for(int j=0;j<h;j++)
          {
            if(v[j][i]=='#' && chk[{j,i}]==0){black--;chk[{j,i}]++;}
          }
        }
      }
      if(black==k){ans++;}
    }
   }
   cout<<ans<<endl;
   return 0;
}
