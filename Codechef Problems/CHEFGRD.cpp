#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x,y;
    cin>>n>>x>>y;
    int ans=x+y;
    if(ans%2==0)cout<<0<<endl;
    else cout<<1<<endl;
  }    
}
