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
        int n,k;
        cin>>n>>k;
        if(k%2==n%2 && n>=k*k)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
