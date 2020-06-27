#include<bits/stdc++.h>
using namespace std;
int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int n,a;
    cin>>n;
    vector<int>v;
    map<int,int>mp;
    int flag=1;
    int m=INT_MIN;
    int ok=0;
    set<int>s;
    for(int i=0;i<n;i++)
    {
      cin>>a;
      m=max(m,a);
      mp[a]++;
      if(mp[a]>2)flag=0;
      if(mp[a]>1)ok=1;
      s.insert(a);
    }
    if(flag==0){cout<<"NO"<<endl;continue;}
    if(mp[m]>1){cout<<"NO"<<endl;continue;}

    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)v.pb(*it);
 
    
    cout<<"YES"<<endl;
  
    if(ok==0)
    {
      for(auto x:v)cout<<x<<" ";
      cout<<endl;
      continue;
    }
    vector<int>ans;
    for(int i=0;i<v.size();i++)
    {
      if(mp[v[i]]>1){ans.pb(v[i]);mp[v[i]]--;}
    }
    ans.pb(m);

    for(int i=v.size()-2;i>=0;i--)
    {
     if(mp[v[i]]==1)ans.pb(v[i]);
    }

    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
   }
  }
