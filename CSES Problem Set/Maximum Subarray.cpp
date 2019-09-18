#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long int n,a,sum=0,ans=INT_MIN,flag=0;
    cin>>n;
    vector<long long int> v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]<0)flag=1;
        else {flag=0;break;}
    }
    if(flag==0)
    {
    for(int i=0;i<n;i++)
    {
        if(sum+v[i]>0)sum=sum+v[i];
        else sum=0;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
    }
    else
    {
        sort(v.begin(),v.end(),greater<int>());
        cout<<v[n-1]<<endl;
        return 0;
    }
    cout<<ans<<endl;
}
