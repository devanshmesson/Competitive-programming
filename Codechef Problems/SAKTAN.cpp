#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q,b,c,even=0,odd=0,c_odd=0;
        cin>>n>>m>>q;
        int v[n+100000]={0};
        int h[m+100000]={0};

        for(int i=0;i<q;i++)
        {
            cin>>b>>c;
            v[b]++;
            h[c]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]%2==0)even++;
            else odd++;
        }
        //cout<<even<<" "<<odd;
        for(int i=1;i<=m;i++)
        {
            if(h[i]%2!=0){c_odd++;}
        }
        int ans1=c_odd*even;
        int ans2=odd*m-c_odd*odd;
       cout<<ans1+ans2<<endl;
    }





    return 0;
}
