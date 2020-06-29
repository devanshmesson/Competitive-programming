//Approach-Sum of two numbers is divisible by k iff sum of their remainders(%k) is divisible by k
#include<bits/stdc++.h>
using namespace std;
int main() 
{
   #define int long long int 
   io
   int t;
   cin>>t;
   while(t--)
   {
     int n,k;
     cin>>n>>k;
     int a[n+1];
     map<int,int>mp;
     bool ok=1;
     int maxi=INT_MIN;
     for(int i=0;i<n;i++)
      {
        cin>>a[i];
        mp[a[i]%k]++;
        if(a[i]%k)maxi=max(maxi,mp[a[i]%k]);
        if(a[i]%k!=0)ok=0;
      }
     int cnt=0;
     if(ok){cout<<0<<endl;continue;}
     int ans=INT_MIN;
     for(int i=0;i<n;i++)
     {
      if(maxi==mp[a[i]%k] && a[i]%k)
      {
        ans=max((k*mp[a[i]%k])-(a[i]%k),ans);
      }
    }
     cout<<ans+1<<endl;
   }
}
