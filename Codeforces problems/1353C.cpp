#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mk make_pair
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int h=n/2;
        int ans=0,c=1;
        for(int i=1;i<=h;i++)
        {
            ans+=(i*8*c);
            c++;
        }
        cout<<ans<<endl;
    }
}
