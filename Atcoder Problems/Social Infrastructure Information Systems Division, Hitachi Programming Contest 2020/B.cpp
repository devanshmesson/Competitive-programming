#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int a,b,m,ans=INT_MAX;
    cin>>a>>b>>m;
    int p[a],q[b];
    int x,y,c;
    for(int i=0;i<a;i++)cin>>p[i];
    for(int i=0;i<b;i++)cin>>q[i];
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>c;
        ans=min(p[x-1]+q[y-1]-c,ans);
    }
    int ans1=INT_MAX;

    sort(p,p+a);
    sort(q,q+b);

    cout<<min(p[0]+q[0],ans)<<endl;

    return 0;
}
