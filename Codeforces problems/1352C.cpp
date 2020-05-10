#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       int ans=k/(n-1);
       if(k%(n-1)==0)cout<<(n*ans)-1<<endl;
       else cout<<(n*ans)+k%(n-1)<<endl;


    }
}
