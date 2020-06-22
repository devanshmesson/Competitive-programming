//Connected Components in an Undirected Graph
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
map<int,int>visit;

int dfs(int s,vector<int>adj[])
{
  if(visit[s]==0)cout<<s<<" ";
  visit[s]=1;

  vector<int>::iterator i;
  for(i=adj[s].begin();i!=adj[s].end();i++)
  {
    if(visit[*i]==0)
    {
      dfs(*i,adj);
    }
  }
  
return 0;
}
main() 
{
   int v,e,a,b;
   cin>>v>>e;
   vector<int>adj[v+1];
   set<int>s;
   for(int i=0;i<e;i++)
   {
    cin>>a>>b;
    s.insert(a);
    s.insert(b);
    adj[a].pb(b);
    adj[b].pb(a);
   }
   set<int>::iterator i;
   cout<<"Connected Components in an Undirected Graph"<<endl;
   for(i=s.begin();i!=s.end();i++)
   {
     if(visit[*i]==0){dfs(*i,adj);cout<<endl;}
   }
}
