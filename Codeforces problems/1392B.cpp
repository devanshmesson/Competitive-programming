#include<bits/stdc++.h>
using namespace std;
main()
{
 int t;
 cin>>t;
 while(t--)
 {
   int n,ma=INT_MIN,k,what,x=INT_MIN,ok=1;;
   cin>>n>>k;
   int a[n+1],b[n+1];
   map<int,int>mp;
   for(int i=0;i<n;i++) 
    {
      cin>>a[i];
      ma=max(ma,a[i]);
      mp[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
      if(!mp[ma-a[i]]){ok=0;break;}
    }
    if(ok && k%2==0)
    {
      for(int i=0;i<n;i++)cout<<a[i]<<" ";
      cout<<endl;
      continue;
    }
    for(int i=0;i<n;i++)
    {
      a[i]=ma-a[i];
      x=max(x,a[i]);
    }
    if(ok && k%2)
    {
      for(int i=0;i<n;i++)cout<<a[i]<<" ";
      cout<<endl;
      continue;
    }
    for(int i=0;i<n;i++)
    {
      b[i]=x-a[i];
    }
    
    if(k%2)
    {
     for(int i=0;i<n;i++)cout<<a[i]<<" ";
      cout<<endl;
      continue;
    }
    else
    {
      for(int i=0;i<n;i++)cout<<b[i]<<" ";
      cout<<endl;
      continue;
    }
  } 
}
