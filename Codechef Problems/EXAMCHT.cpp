#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll div(ll x)
{
    ll cnt=0;
    for(ll i=1;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            if(x/i==i){cnt++;}
            else {cnt+=2;}
        }

    }
    return cnt;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<div(abs(b-a))<<endl;
    }

    return 0;
}
