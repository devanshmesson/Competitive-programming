//Applied Difference Array
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
const int MOD=1e9+7;
const int add=5e5;
const int N=1e6+10;
int d[N];
int32_t main()
{
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,a,b;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            d[a+add]++;
            d[b+1+add]--;
        }
        int ans=0;
        for(int i=1;i<N;i++)
        {
            d[i]+=d[i-1];
            ans+=d[i];
        }
        cout<<ans%MOD<<endl;





    return 0;
}

