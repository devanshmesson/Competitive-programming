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
        int n,sum=0,in=0,index,s,a;
        cin>>n>>s;
        int v[n];
        for(int i=0;i<n;i++)
        {
            cin>>v[i]; sum+=v[i];
        }
        if(sum<=s){cout<<0<<endl;continue;}
        if(n==1){if(v[0]<s)cout<<0<<endl;else cout<<1<<endl;continue;}

        for(int i=0;i<n;i++)
        {
            in+=v[i];
            if(in>s){index=i;break;}
        }
        cout<<find(v,v+index,*max_element(v,v+index+1)) - v + 1<<endl;

    }
    return 0;
}
