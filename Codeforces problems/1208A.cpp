#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int a,b,c,d;
       cin>>a>>b>>d;
       int h=a^b;
       int f[3];
       f[0]=a;
       f[1]=b;
       f[2]=h;
       cout<<f[d%3]<<endl;
    }
}
