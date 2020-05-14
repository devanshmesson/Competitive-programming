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
        int n,k;
        cin>>n>>k;
        int a[n+1],b[n+1];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=max(a[i],b[i]);
        }

        for(int i=k;i<n;i++)sum+=a[i];
        cout<<sum<<endl;
    }
}
