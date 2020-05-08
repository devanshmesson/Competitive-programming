#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int diff[n+1];
    for(int i=1;i<n;i++)
    {
        diff[i-1]=a[i-1]-a[i];
    }
    sort(diff,diff+n-1);
    int ans=a[n-1]-a[0];
    for(int i=0;i<k-1;i++)
    {
        ans+=diff[i];
    }
    cout<<ans<<endl;

}
