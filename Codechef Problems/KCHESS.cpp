#include<bits/stdc++.h>
using namespace std;
main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int n,a,b,x,y;
    cin>>n;
    map<pair<int,int>,int>check;
    for(int i=0;i<n;i++)
    {
      cin>>x>>y;

      check[{x-1,y+2}]++;
      check[{x-1,y-2}]++;

      check[{x+1,y-2}]++;
      check[{x+1,y+2}]++;

      check[{x-2,y-1}]++;
      check[{x-2,y+1}]++;

      check[{x+2,y-1}]++;
      check[{x+2,y+1}]++;
    }
    cin>>x>>y;
    bool flag=1;
    for(int i=x-1;i<=x+1;i++) for(int j=y-1;j<=y+1;j++) if(!check[{i,j}]){flag=0;break;}

    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   }  
  return 0;
}
