#include <bits/stdc++.h>
using namespace std;
#define int long long int
int ans=0;
int f(int n)
{
    int d=1,in,cd,g,k,i=1;
    while(1)
    {
      d=i*i + i  +(i*(i-1))/2;
      if(d>n){in=i-1;break;}
      i++;
    }
    if(in>1)cd=in*in +in+(in*(in-1))/2;
    else cd=2;
    g=n/cd;
    ans+=g;
    k=n%cd;
    if(k!=0 && k!=1)f(k);
    else return ans;
}
main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       ans=0;
       cout<<f(n)<<endl;
    }
    return 0;
}
