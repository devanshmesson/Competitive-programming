#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,minm=INT_MAX,b,c;
    cin>>n;
    vector<pair<int,int> > v;
    int ar[n+20];
    for(int i=0;i<n;i++) cin>>ar[i];
    for(int i=0;i<n-1;i++)
    {
         v.push_back(make_pair(ar[i],ar[i+1]));
    }
    v.push_back(make_pair(ar[0],ar[n-1]));
    for(int i=0;i<n;i++)
    {
        int d=fabs(v[i].first-v[i].second);
        if(d<=minm) {minm=d;b=v[i].first;c=v[i].second;}
    }

    for(int i=0;i<n;i++)
    {
        if(b==ar[i] && c==ar[i+1]){cout<<i+1<<" "<<i+2;break;}
        else if(b==ar[0] && c==ar[n-1]){cout<<1<<" "<<n;break;}
    }

    return 0;
}
