#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int h,n,cnt=0,a;
    cin>>h>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cnt+=a;
    }
    if(cnt>=h)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
