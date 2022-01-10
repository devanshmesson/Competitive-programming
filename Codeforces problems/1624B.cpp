// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int yes()
{
  cout<<"YES"<<endl;
}
signed main()
{
//   freopen
  int t;
  cin>>t;
  while(t--)
  {
    int a,b,c;
    cin>>a>>b>>c;
    if(b-a==c-b){cout<<"YES"<<endl;continue;}
    // change b
    if((a+c)%(2*b)==0 && (a+c)>0)
    {
      yes();continue;
    }
    //change a
    if(((2*b)-c)%a==0 && ((2*b)-c)>0)
    {
      yes();continue;
    }
    //change c
    if(((2*b)-a)%c==0 && ((2*b)-a)>0)
    {
       yes();continue;
    }
    cout<<"NO"<<endl;
  }
}
