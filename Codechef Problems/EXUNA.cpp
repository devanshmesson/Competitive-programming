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
        int n,ans;
        cin>>n;
        vector<int> v;
        int a;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        ans=v[0];
        for(int i=1;i<n;i++)
        {
            ans=ans%v[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
