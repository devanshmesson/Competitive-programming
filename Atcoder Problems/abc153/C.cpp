#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int n,k,a,cnt=0,p=0;
    vector<int>v;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;v.push_back(a);
    }
    if(k>=n){cout<<0<<endl;return 0;}
    else
    {
        sort(v.begin(),v.end(),greater<int>());
        if(k>=1)p+=k;
        else p=0;
        for(int i=p;i<n;i++)
        {
            cnt+=v[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}
