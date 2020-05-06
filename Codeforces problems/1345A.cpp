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
        int n,m;
        cin>>n>>m;
        if(n==1)cout<<"YES"<<endl;
        else if(n==2 && m<3)cout<<"YES"<<endl;
        else if(n>=3 && m==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
