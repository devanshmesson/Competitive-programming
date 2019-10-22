#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,a,cnt=0;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
        if(fabs(v[i]-v[j])==1){cnt++;}
        }
    }
    if(cnt==0)cout<<"1"<<endl;
    else cout<<"2"<<endl;
    }
 
 
    return 0;
}
