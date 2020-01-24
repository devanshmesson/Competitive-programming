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
        int n,k,s,ans=0,m,r=1000;
        cin>>n>>s>>k;
        bool f=1;
        m=min(n-1,r);
        int a[m];
        for(int i=0;i<k;i++)
        {
            cin>>a[i]; if(a[i]==s)f=0;
        }
        if(f){cout<<0<<endl;continue;}
        sort(a,a+k);
 
        while(1)
        {
            if(!binary_search(a,a+k,s+ans)&& s+ans<=n){cout<<ans<<endl;break;}
            if(!binary_search(a,a+k,s-ans) && s-ans>=1){cout<<ans<<endl;break;}
            ans++;
 
        }
    }
    return 0;
}
