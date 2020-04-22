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
       int k,n,a,b;
       cin>>k>>n>>a>>b;
       int d=k-(n*a);
       if(d>0)cout<<n<<endl;
       else if(d<=0)
       {
          d=abs(k-(n*a));
          int diff=abs(a-b);
          int g=(float)d/(float)diff;
          if(g<=n)
          {
              int y=n-g;
              if((y*a) + (g*b)<k){cout<<n-g<<endl;continue;}
          }
          if(g+1<=n)cout<<n-(g+1)<<endl;
          else cout<<-1<<endl;
       }
    }

    return 0;
}
