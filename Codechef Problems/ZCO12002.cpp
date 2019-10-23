#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fn=100000;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<pair <ll,ll> > vec;
    vector<ll>v1,w1,a;
    ll n,x,y,p,q;
    cin>>n;
    cin>>x;
    cin>>y;

   for(ll i=0;i<n;i++){ cin>>p>>q; vec.push_back(make_pair(p,q)); }
   for(ll i=0;i<x;i++){ cin>>p;  v1.push_back(p);}
   for(ll i=0;i<y;i++){ cin>>p;  w1.push_back(p);}

    sort(vec.begin(),vec.end());
    sort(v1.begin(),v1.end());
    sort(w1.begin(),w1.end());

    for(ll i=0;i<n;i++)
    {
        if(v1[0]<=vec[i].first && w1[y-1]>=vec[i].second)
        {
       ll l=lower_bound(v1.begin(),v1.end(),vec[i].first) - v1.begin()-1;
       ll u=upper_bound(w1.begin(),w1.end(),vec[i].second)-w1.begin();
       ll int lo=v1[l];
       ll int up=w1[u];
       if(v1[l+1]==vec[i].first) lo=vec[i].first;
       if(w1[u-1]==vec[i].second)  up=vec[i].second;
       fn=min(up-lo+1,fn);
        }
    }
   cout<<fn;
   return 0;
}
