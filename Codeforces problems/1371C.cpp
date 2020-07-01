#include<bits/stdc++.h>
using namespace std;
main() 
{
   int t;
   cin>>t;
   while(t--)
   {
     int v,c,n,m;
     cin>>v>>c>>n>>m;
     if(min(v,c)<m){cout<<"No"<<endl;continue;}
     if(min(c,v)==0 && n==0 && m>=1){cout<<"No"<<endl;continue;}
     if(v+c<n+m){cout<<"No"<<endl;continue;}
     if(max(v,c)-min(v,c)>n && min(v,c)>m){cout<<"Yes"<<endl;continue;}
     if(c==0 && v==0){cout<<"No"<<endl;continue;}
     c-=m;
     if(v+c>=n)cout<<"Yes"<<endl; 
   }
}
