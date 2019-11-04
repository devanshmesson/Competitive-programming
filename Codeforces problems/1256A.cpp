#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n,s,flag=1;
        cin>>a>>b>>n>>s;

       int div=s/n;

       if(a>div || a==div)a=div;

       if(a*n+b>=s)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }

    return 0;
}
