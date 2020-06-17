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
   string s;
   cin>>s;
   int sz=s.size();
   int ans=0;
   vector<int>v;
   for(int i=0;i<n;i++)
   {
    if(s[i]=='1'){v.pb(i);}
   }
   int j=0;
   if(v.size()==0)for(int i=0;i<n;i+=k+1)ans++;
   else if(v.size()==1)
   {
   
    for(int i=0;i<n;)
    {
      if(abs(i-v[0])>=(k+1))
      {
       ans++;
       i+=(k+1);
      }
      else i++;
     }
   }

   else if(v.size()>=2)
   {
    for(int i=0;i<v[0];)
    {
     if(abs(i-v[0])>=(k+1))
      {
       ans++;
       i+=(k+1);
      }
      else i++;
    }
   
    for(int i=v[0];i<v[v.size()-1];)
    {
     if(i>=v[j+1])j++;
     if(abs(i-v[j])>=(k+1) && abs(i-v[j+1])>=(k+1) && (j+1)<(v[v.size()-1]))
     {
       ans++;
       i+=(k+1);
       if(i>=v[j+1])j++;
     }
     else {i++; if(i>=v[j+1])j++;}
    }

    for(int i=v[v.size()-1];i<n;)
    {
      if(abs(i-v[v.size()-1])>=(k+1))
      {
       ans++;
       i+=(k+1);
      }
     else i++;
    }
 }
   cout<<ans<<endl;
 }
}
