#include <bits/stdc++.h>
using namespace std;
int power(int x, unsigned int y)
{
    int res=1;
    while(y>0)
    {
        if(y&1)res=res*x;
        y=y>>1;
        x=x*x;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
     #define int long long int
     int t;
     cin>>t;
     while(t--)
     {
         int c,sum,temp,ans,flag=1,a;
         cin>>c>>sum;
         if(c>sum){cout<<sum<<endl;continue;}
         else
         {
            a=sum/c;
            temp=sum%c;
            ans=temp*power(a+1,2)+(c-temp)*power(a,2);
         }
         cout<<ans<<endl;
     }
    return 0;
}
