#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int h,p;
    cin>>h>>p;
    while(p>0)
    {
      h-=p;
      p/=2;
    }
    if(h>0)cout<<0<<endl;
    else if(h<=0)cout<<1<<endl;
  }
}
