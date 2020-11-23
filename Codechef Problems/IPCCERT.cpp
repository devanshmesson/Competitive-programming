#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define int long long int
main()
{
   int n,m,k,a,q,ans=0;
   cin>>n>>m>>k;
   int cnt=0;
   for(int i=0;i<n;i++)
   {
     cnt=0;
     for(int j=0;j<k;j++)
     {
       cin>>a;
       cnt+=a;
     }
     cin>>q;
     if(q<=10 && cnt>=m)ans++;
   }
   cout<<ans<<endl;
}
