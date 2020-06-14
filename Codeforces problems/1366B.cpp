#include<bits/stdc++.h>
using namespace std;
#define pb push_back
main() 
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x,m,a,b,ans=1,ok=0;
    cin>>n>>x>>m;
    int l=x,r=x;
    for(int i=0;i<m;i++)
    {
      cin>>a>>b;
      if(max(l,a)<=min(r,b))
      {
        l=min(l,a);
        r=max(r,b);
      }
    }
    cout<<r-l+1<<endl;
  }  
  return 0;
}
