#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    int n,t,b,m=INT_MAX,c;
    cin>>n>>t;
    int a[n+10];
    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=0;i<t;i++)
    {
        cin>>c>>b;
        m=INT_MAX;
        for(int j=c;j<=b;j++)
        {
            m=min(m,a[j]);
        }
        cout<<m<<endl;
    }
}
