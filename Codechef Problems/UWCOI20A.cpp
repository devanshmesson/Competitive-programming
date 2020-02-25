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
        int n;
        cin>>n;
        int a,ans=0;

        for(int i=0;i<n;i++)
        {
            cin>>a;
            ans=max(ans,a);

        }
        cout<<ans<<endl;
    }


    return 0;
}
