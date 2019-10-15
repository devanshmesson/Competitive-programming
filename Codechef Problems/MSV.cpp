#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,star[1002000]={0},ans=0,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            ans=max(ans,star[a]);
            for(int j=1;j*j<=a;j++) {if(a%j==0){star[j]++;if(j*j!=a)star[a/j]++;}}
        }
        cout<<ans<<endl;
    }
    return 0;
}
