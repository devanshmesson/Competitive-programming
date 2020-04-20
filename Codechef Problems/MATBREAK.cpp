#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
#define int long long int
int power(int x, unsigned int y)
{
    int res = 1;     
    while (y > 0)
    {
       
        if (y & 1){res = res*x;res=res%mod;}
        y = y>>1; 
        x = x*x;
        x=x%mod; 
    }
    return res%mod;
}
main()
{
     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #define pb push_back
     #define mk make_pair
     int t;
     cin>>t;
     while(t--)
     {
         int n,a,g,j;
         int sum=0;
         cin>>n>>a;
         g=a;
         for(int i=1;i<=n;i++)
         {
            sum+=power(g,(2*i)-1);
            sum=sum%mod;
            j=power(g,(2*i)-1);
            j=j%mod;
            g*=j;
            g=g%mod;
  }
         cout<<sum%mod<<endl;
     }


    return 0;
}
