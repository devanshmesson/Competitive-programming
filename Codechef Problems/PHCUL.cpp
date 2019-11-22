#include <bits/stdc++.h>
using namespace std;
int N=100000;
#define ld long double
ld INF_MAX= 1e10;

ld dis(long long int x1,long long int y1,long long int x2,long long int y2)
{
    ld dx=abs(x1-x2);
    ld dy=abs(y1-y2);
    return sqrt(dx*dx+dy*dy);
}

int main()
{
   ios::sync_with_stdio();cin.tie(0);cout.tie(0);
   #define int long long int
   int t;
   cin>>t;
   while(t--)
   {
       int x,y,n,m,k;
       int a[N],b[N],c[N],d[N],e[N],f[N];
       ld a1[N],b1[N],a2[N],b2[N];
       cin>>x>>y>>n>>m>>k;

       for(int i=0;i<n;i++) cin>>a[i]>>b[i];
       for(int i=0;i<m;i++) cin>>c[i]>>d[i];
       for(int i=0;i<k;i++) cin>>e[i]>>f[i];

       for(int i=0;i<n;i++) { a2[i]=dis(x,y,a[i],b[i]);a1[i]=INF_MAX; for(int j=0;j<k;j++) a1[i]=min(a1[i],dis(a[i],b[i],e[j],f[j]));}
       for(int i=0;i<m;i++) { b2[i]=dis(x,y,c[i],d[i]);b1[i]=INF_MAX; for(int j=0;j<k;j++) b1[i]=min(b1[i],dis(c[i],d[i],e[j],f[j]));}
       ld ans=INF_MAX;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               ans=min({ans,
                       a2[i]+dis(a[i],b[i],c[j],d[j])+b1[j],
                       b2[j]+dis(a[i],b[i],c[j],d[j])+a1[i]});
           }
       }
       cout<<fixed<<setprecision(10)<<ans<<endl;




   }

    return 0;
}
