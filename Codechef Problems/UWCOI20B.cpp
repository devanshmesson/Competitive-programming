#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0,cnt1=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)cnt++;
            else if(a[i]%2!=0)cnt1++;
        }
        if(cnt==0 || cnt1==0){cout<<0<<endl;continue;}
         cout<<cnt*cnt1<<endl;

    }



    return 0;
}
