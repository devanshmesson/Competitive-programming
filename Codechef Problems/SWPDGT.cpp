#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int q;
    cin>>q;
    while(q--)
    {
        int a,b,a1,a2,b1,b2,mx=INT_MIN;
        cin>>a>>b;
        a1=a%10;
        a2=a/10;
        b1=b%10;
        b2=b/10;
        mx=max(mx,(a2+b2)*10 + a1+b1);
        if(b2)mx=max(mx,(a1+a2)*10+b1+b2);
        if(a2)mx=max(mx,(b1+b2)*10+a1+a2);
        if(a2 && b2){mx=max(mx,(a1+a2)*10+b1+b2);mx=max(mx,(b1+b2)*10+a1+a2);}
        cout<<mx<<endl;

    }
    return 0;
}
