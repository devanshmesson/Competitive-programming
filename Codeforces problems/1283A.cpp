#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio();cin.tie();cout.tie();
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int h,m,h1,m1;
        cin>>h>>m;
        h1=23-h;
        m1=60-m;
        int ans=h1*60+m1;
        cout<<ans<<endl;
    }
    return 0;
}
