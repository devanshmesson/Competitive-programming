#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5],cnt[n+5]={0};
        int sum=0;
        for(int i=0;i<n;i++)cin>>a[i];
        int l=0,r=1;
        for(int i=0;i<n;i++)
        {
            sum=a[i];
            for(int j=i+1;j<n;j++)
            {
                sum+=a[j];
                if(sum<=n)cnt[sum]++;
            }

        }
        int ans=0;
        for(int i=0;i<n;i++)if(cnt[a[i]]>0)ans++;
        cout<<ans<<endl;


    }
}
