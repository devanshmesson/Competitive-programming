#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    float n,t=1,sum=0,s=0;
    cin>>n;
    while(n!=0)
    {
        sum+=t/n;
        n--;
    }
    cout<<setprecision(10)<<fixed<<sum<<endl;






    return 0;
}
