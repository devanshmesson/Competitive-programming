#include<bits/stdc++.h>
using namespace std;
int main() 
{
   #define int long long int 
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     cin>>n;
     int a[n+1];
     for(int i=0;i<n;i++)
     {
       cin>>a[i];
     }
     int mini=INT_MAX,maxi=INT_MIN,cnt=1,infect;
     for(int i=0;i<n;i++)
     {
       cnt=1;
       infect=a[i];
       for(int j=i-1;j>=0;j--)   //People standing to the left of infected person
       {
         if(abs(infect-a[j])<=2)
         {
          cnt++;
          infect=a[j];
         }
       }
       infect=a[i];
       for(int j=i+1;j<n;j++)    //People standing to the right of infected person
       {
         if(abs(infect-a[j])<=2)
         {
          cnt++;
          infect=a[j];
         }
       }
      
      mini=min(mini,cnt);   //Calculating minimum and maximum count of total infected persons
      maxi=max(maxi,cnt);
     }
     cout<<mini<<" "<<maxi<<endl;
   }
}
