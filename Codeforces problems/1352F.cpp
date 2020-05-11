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
        int a,b,c;
        cin>>a>>b>>c;
        int a1=a;
        int b1=b;
        if(b%2==0 && b>0){cout<<1;b--;}
        if(a>0 )a++;

        while(a>0)
        {
            cout<<"0";
            a--;
        }
        int cnt=0;
        if(a1==0 && b>0){cout<<0;}



        while(b>0)
        {
            if(cnt%2==0)cout<<1;
            else if(cnt%2!=0)cout<<0;
            cnt++;
            b--;
        }
        if(b1==0 && c>0)c++;
        while(c>0)
        {
            cout<<1;
            c--;
        }
        cout<<endl;

    }
}
