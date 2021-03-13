#include<bits/stdc++.h>
using namespace std;

main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
   int n;
   cin>>n;
   int a[n+1],b[n+1],tm[n+1];
   a[0]=0; b[0]=0;
   for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
   for(int i=1;i<=n;i++)cin>>tm[i];
   
   int aa[n+1],bb[n+1];

   aa[0]=0; bb[0]=0;
   
   for(int i=1;i<=n;i++)
   {
     int move=a[i]-b[i-1];
     aa[i]=bb[i-1]+move+tm[i];

     int diff = (b[i] - a[i]);
     if(diff % 2==1)diff=(diff/2)+1;
     else diff=(diff/2);
     bb[i]=aa[i]+diff;
     if(bb[i]<b[i]) bb[i]+=b[i]-bb[i];
   }

   cout<<aa[n]<<endl;


 }

} 
 
