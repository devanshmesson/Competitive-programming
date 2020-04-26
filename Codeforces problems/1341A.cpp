#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    int t;
    cin>>t;
    while(t--)
    {
       int n,a,b,c,d,flag=1;
       cin>>n>>a>>b>>c>>d;
       int m=a-b;
       int k=a+b;
       int g=c-d;
       int p=c+d;
       if(n*m>p || n*k<g)cout<<"No"<<endl;
       else cout<<"Yes"<<endl;


    }
    return 0;
}
