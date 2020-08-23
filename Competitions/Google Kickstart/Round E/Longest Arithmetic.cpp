#include<bits/stdc++.h>
using namespace std;
main()
{ 
 int tt;
 cin>>tt;
 for(int i=1;i<=tt;i++)
 {
   int n;
   cin>>n;
   int a[n+1];
   for(int i=0;i<n;i++)cin>>a[i];
   int ans=a[0]-a[1],cnt=0,flag=0,maxi=0;
   for(int i=1;i<n-1;i++)
   {
     if(a[i]-a[i+1]==ans && i+1<n)
     {
       if(flag==0){cnt=3;flag=1;}
       else cnt++;
     }
     else 
     {
       maxi=max(maxi,cnt);
       if(flag==0){maxi=2;flag=1;}
       cnt=0;
       ans=a[i]-a[i+1];
       cnt=2;
     }
   }
   maxi=max(maxi,cnt);
   if(n==2)maxi=2;
  cout<<"Case #"<<i<<": "<<maxi<<endl;
 }
}
