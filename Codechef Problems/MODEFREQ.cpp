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
    int a[n+1];
    map<int,int>mp;
    for(int i=0;i<n;i++){cin>>a[i];mp[a[i]]++;}
    int ans=INT_MAX;
    map<int,int>cp;
    for(auto x:mp)
    {
      cp[x.second]++;
    }
    int mx=INT_MIN;
   for(auto x:cp)
   {
     mx=max(mx,x.second);
   }
   for(auto x:cp)
   {
     if(x.second==mx)
     {
        ans=min(ans,x.first);
     }
   }
   cout<<ans<<endl;    
 }
}
