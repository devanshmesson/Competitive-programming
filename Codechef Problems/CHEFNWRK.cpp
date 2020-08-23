#include<bits/stdc++.h>
using namespace std;
main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
   int n,k;
   cin>>n>>k;
   int a[n+1];
   int ok=0;
   for(int i=0;i<n;i++){cin>>a[i];if(a[i]>k)ok=1;}
  if(ok)
  {
    cout<<-1<<endl;
    continue;
  }
   int ans=0,sum=1;
   for(int i=0;i<n;i++)
   { 
     ans+=a[i];
     if(ans>k)
     {
      sum++;
      ans=a[i];
     }
   }
   cout<<sum<<endl;
 }
}
