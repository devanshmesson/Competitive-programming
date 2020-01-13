#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pown(ll x,ll y)
{
    ll res = 1;
   while (y > 0)
    {
        if (y & 1)
            res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,c,d,e,s,x;
        cin>>n;
        cin>>a;
        int p=pown(10,n)-1;
        s=a+(2*p)+2;
        cout<<s<<endl;
        cin>>b;
        c=pown(10,n)-1-b+1;
        cout<<c<<endl;
        cin>>d;
        e=pown(10,n)-1-d+1;
        cout<<e<<endl;
        cin>>x;
        if(x==1)continue;
        else break;

    }
    return 0;
}
