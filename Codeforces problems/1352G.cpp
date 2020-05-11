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
        int n,pres,ok;
        cin>>n;
        if(n%2==0)ok=1;
        else ok=0;
        if(n<=3){cout<<-1<<endl;continue;}
        for(int i=2;i<=n;i+=2){cout<<i<<" ";pres=i;}
        pres=pres-3;
        cout<<pres<<" ";
        for(int i=n-ok;i>=0;i-=2)
        {
            if(i!=pres)cout<<i<<" ";
        }
        cout<<endl;

    }
}
