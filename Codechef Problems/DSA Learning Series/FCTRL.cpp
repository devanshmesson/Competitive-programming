#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    #define endl "\n"
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,c=0,flag=1;
        cin>>n;
        for(int i=5;i<=n;i*=5)
        {
          c+=n/i;
        }

        cout<<c<<endl;

    }
    return 0;
}


