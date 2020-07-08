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
     int a[n+1],b[n+1];
     bool ok=1,ok1=1;
     for(int i=0;i<n;i++)cin>>a[i];
     for(int i=0;i<n;i++)
     {
      cin>>b[i];
      if(a[i]>b[i])ok=0;
      if(a[n-i-1]>b[i])ok1=0;
     }
     if(ok1 && ok){cout<<"both"<<endl;}
     else if(ok)cout<<"front"<<endl;
     else if(ok1) cout<<"back"<<endl;
     else cout<<"none"<<endl;
   }
  return 0;
}
