#include <bits/stdc++.h>
using namespace std;
#define int long long int
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
main()
{
    int w,h;
    cin>>w>>h;
    int ans=power(2,w-1+h-1,998244353);
    int an=ans*pow(2,2);
    cout<<an%(998244353)<<endl;

    return 0;
}
