//Author-Devansh
#include <bits/stdc++.h>
using namespace std;
#define int long long int
int power(int x, unsigned int y)
{
    int res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;

        // y must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s=0;
        for(int i=1;i<=n/2;i++)
        {
s+=power(2,i);

        }
        cout<<s<<endl;

    }

     return 0;
}
