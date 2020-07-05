#include<bits/stdc++.h>
using namespace std;
main() 
{
   int t,n,m;
   cin>>t;
   int mi=INT_MIN,ans,s1=0,s2=0;
   while(t--)
   {
      cin>>n>>m; 
      s1+=n;s2+=m;
      if(mi<=abs(s1-s2))
      {
        mi=abs(s1-s2);
        if(n>m)ans=1;
        else ans=2;
      }
   }
   cout<<ans<<" "<<mi<<endl;
  return 0;
}
