#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n;
    vector<int> v;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)v.push_back(i);
    }
    double s=v.size();
    double ans=s/n;
    cout<<ans<<endl;
    return 0;
}
