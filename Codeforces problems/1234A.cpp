#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,a;
    cin>>t;
    while(t--)
    {
    double sum=0,avg=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
    }
    avg=sum/n;
    if(ceil(avg)==avg)cout<<(int)avg<<endl;
    else cout<<(int)avg+1<<endl;
    }
    return 0;
}
