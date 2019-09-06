#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,e,ans;
    cin>>n>>d>>e;
    ans=n;

    for(int i=0;i*5*e<=n;i++)
    {
        ans=min(ans,(n-i*5*e)%d);
    }
    cout<<ans<<endl;
    return 0;
}
