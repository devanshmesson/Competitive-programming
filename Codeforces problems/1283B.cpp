#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k,ans,a;
        cin>>n>>k;
        a=n/k;
        ans=(a*k)+min(n%k,k/2);
        cout<<ans<<endl;

    }
    return 0;
}
