#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    //#define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=INT_MAX,m;
        vector<int>v;
        cin>>n>>m;
        int a[10000]={0},b[10000]={0},c[10000]={0};
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        set<int>s;
        for(int i=0;i<n;i++)
        {
            c[a[i]]+=b[i];
            s.insert(a[i]);
        }
        set<int>::iterator itr;
        for(itr=s.begin();itr!=s.end();itr++){ans=min(ans,c[*itr]);}
        cout<<ans<<endl;

    }

    return 0;
}
