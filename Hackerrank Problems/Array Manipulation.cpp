#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    int n,m,b,k,q=INT_MIN,w,c;
    cin>>n>>m;
    vector<int>a(n+10);
    
    for(int i=0;i<m;i++)
    {
        cin>>c>>b>>k;
        a[c]+=k;
        if(b!=n)a[b+1]-=k;
    }
    for(int i=2;i<=n;i++){a[i]+=a[i-1];q=max(q,a[i]);}
    q=max(q,a[1]);
    cout<<q<<endl;

}
