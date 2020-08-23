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
   for(int i=0;i<n;i++)cin>>a[i];
   int dp[n+1];
   memset(dp,1e9,sizeof(dp));

   for(int i=0;i<n;i++)
   {
     dp[i]=k;
     if(i>0)dp[i]+=dp[i-1];
     map<int,int>mp;
     int conflict=0;
     mp[a[i]]++;
     for(int j=i-1;j>=0;j--)
     {
       mp[a[j]]++;
       if(mp[a[j]]==2)
        {
          conflict+=2;
        }
        else if(mp[a[j]]>2)conflict++;
    
       if(j>0)dp[i]=min(dp[i],conflict+dp[j-1]+k);
       else dp[i]=min(dp[i],conflict+k);
     }
   }
   cout<<dp[n-1]<<endl;
 }
}
