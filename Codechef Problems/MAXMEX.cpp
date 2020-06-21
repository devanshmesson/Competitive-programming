#include<bits/stdc++.h> 
using namespace std; 
main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int n,m,ok=0,b;
    cin>>n>>m;
    vector<int>a;
    map<int,int>s;
    for(int i=0;i<n;i++)
    {
      cin>>b;
      s[b]++;
      if(b==1)ok=1;
    }
    if(ok==0){cout<<-1<<endl;continue;}
    int cnt=0,c=0,v=0,ans=0;
 
   for(auto x:s) { a.pb(x.first); v++;}

    for(int i=0;i<v;i++)
    {
      if(a[i]<m){cnt++; ans+=(s[a[i]]);}
      else if(a[i]>m){c++;ans+=(s[a[i]]);}
    }
    if(cnt==m-1)cout<<ans<<endl;
    else cout<<-1<<endl;
    }
}
