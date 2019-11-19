#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,sum=0,cnt=0,t1;
        cin>>a>>b;
        int d=fabs(a-b);

        if(d>=5)
        {
            cnt+=d/5;
            d=d%5;
        }
         if(d<5 && d>=2)
        {
            cnt+=d/2;
            d=d%2;
        }
        if(d<2 && d>=1)
        {
            cnt+=d/1;
            d=d%1;
        }
       cout<<cnt<<endl;


    }
    return 0;
}
