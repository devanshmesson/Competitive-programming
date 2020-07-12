#include<bits/stdc++.h>
using namespace std;
main() 
{
   #define int long long int 
   int t;
   cin>>t;
   while(t--)
   {
     int n,x;
     cin>>n>>x;
     int a[n+1],much=0,sofar=0;
     for(int i=0;i<n;i++)cin>>a[i];
     sort(a,a+n,greater<int>());
     int ans=0;
     for(int i=0;i<n;i++)
     {
      if(a[i]>=x)ans++;
      else if(x>a[i])
      {
        much=0;
        if(x%a[i]!=0)much++;
        much+=(x/a[i]);
        much--;
        if(sofar>=much)
        {
          ans++;
          sofar-=much;
        }
        else sofar++;
      }
     }
     cout<<ans<<endl;
   }
  return 0;
}
