#include<bits/stdc++.h>
using namespace std;
main() 
{
  int n,ok=0,ok1=0;
  cin>>n;
  int a[n+1];
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i]%2)ok=1;
      else ok1=1;
    }
    
    if(ok && ok1)
    {
      sort(a,a+n);
      for(int i=0;i<n;i++)cout<<a[i]<<" ";
    }
   else
   {
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
   }
  return 0;
} 
