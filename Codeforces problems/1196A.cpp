#include<bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int f[3];
        f[0]=a;
        f[1]=b;
        f[2]=c;
        sort(f,f+3);
        int u=f[0];
        f[0]+=(f[1]-f[0]);
        f[2]-=(f[1]-u);

        int e=f[2]/2;
        f[0]+=e;
        cout<<f[0]<<endl;


    }
}
