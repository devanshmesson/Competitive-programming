#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define freopen //comment
#endif
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define int long long int
//#define endl "\n"
main() 
{ 
  io
 //freopen
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int c[10000]={0};
    set<int>s;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      c[a[i]]++;
      s.insert(a[i]);
    }
    set<int>::iterator it;
    vector<int>v;
    for(it=s.begin();it!=s.end();it++)
    {
      v.push_back(*it);
    }
    int flag=1;
    for(int i=0;i<v.size();i++)
    {
      for(int j=i+1;j<v.size();j++)
      {
        if(c[v[i]]==c[v[j]]){flag=0;break;}
      }
      if(flag==0)break;
    }
    int f=1;
    for(int i=0;i<v.size();i++)
    {
      int upd=INT_MAX;
      for(int j=0;j<n;j++)
      {
        if(a[j]==v[i])
        {
          if(abs(upd-j)>1 && upd!=INT_MAX){f=0;break;}
          upd=j;
        }
      }
      if(f==0)break;
    }

  if(flag==0 || f==0)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;

  }

}
