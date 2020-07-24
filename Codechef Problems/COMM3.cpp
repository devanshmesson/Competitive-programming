#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int r,a,b,c,d,e,f,ans1,ans2,ans3,ans=0;
    cin>>r>>a>>b>>c>>d>>e>>f;
    r*=r;
    ans1=((a-c)*(a-c))+((b-d)*(b-d));
    ans2=((e-c)*(e-c))+((f-d)*(f-d));
    ans3=((a-e)*(a-e))+((b-f)*(b-f));
    if(ans1<=r)ans++;
    if(ans2<=r)ans++;
    if(ans3<=r)ans++;
    if(ans>=2)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}
