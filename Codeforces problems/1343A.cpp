#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,i=1,sum=1;
    cin>>n;
    while(1)
    {
        sum+=(1<<i);
        if(n%sum==0){cout<<n/sum<<endl;break;}
        i++;
    }
    }
}
