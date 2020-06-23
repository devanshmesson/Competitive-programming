#include<bits/stdc++.h> 
using namespace std;
#define pb push_back
main() 
{
   int v,e,a,b;
   cin>>v>>e;
   map<int,int>visit;
   stack<int>s;
   vector<int>adj[v+1];
   for(int i=0;i<e;i++)
   {
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
   }
   vector<int>::iterator it;
   for(int i=0;i<v;i++)
   {
      if(visit[i]==0)
      {
        s.push(i);
        while(!s.empty())
        {
          int d=s.top();
          s.pop();
          if(!visit[d]){cout<<d<<" ";visit[d]=1;}
          for(it=adj[d].begin();it!=adj[d].end();it++)
          {
            if(!visit[*it])s.push(*it);
          }
        }
      }

   }
} 
