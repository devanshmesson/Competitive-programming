include<bits/stdc++.h>
using namespace std;
#define int long long int
main() 
{
  int t;
  cin>>t;
  while(t--)
  {
   int n,flag=1;
   cin>>n;
   int a[n+1];
   map<int,int>mp;
   for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    if(n%2!=0){cout<<-1<<endl;continue;}
    int mn=INT_MAX;
 
   for(int i=0;i<n;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       int x=a[i]^a[j];
       mp[x]++;
       if(mp[x]==n/2){flag=0;mn=min(mn,x);}
     }
   }
  if(flag==0)cout<<mn<<endl;
  else cout<<-1<<endl;
  }
}  
