#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,c,te,itr,ans=0,an=1000000009,ind;
        cin>>n;
        int s[n],p[n],v[n+10000];
        for(int i=0;i<n;i++)
        {
            cin>>s[i]>>p[i]>>v[i];
            s[i]++;
        }

        for(int i=0;i<n;i++)
        {
            ans=max(ans,(p[i]/s[i])*v[i]);
        }
        cout<<ans<<endl;

    }
    return 0;
}
