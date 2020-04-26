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
       int x,y,a,b,ans;
       cin>>x>>y;
       cin>>a>>b;
       int ans2=(x+y)*a;
       int d=min(x,y);
       ans=d*b;
       x-=d;y-=d;
       if(y>0)
       {
           ans+=y*a;
       }
       else if(x>0)ans+=x*a;


       cout<<min(ans,ans2)<<endl;

    }
    return 0;
}
