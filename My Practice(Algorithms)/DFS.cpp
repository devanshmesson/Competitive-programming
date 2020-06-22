#include<bits/stdc++.h>
using namespace std;
map<int,int>visit;

int dfs(int s,vector<int>adj[])
{
  if(visit[s]==0)cout<<s<<endl;
  visit[s]=1;
  vector<int>::iterator i;
  for(i=adj[s].begin();i!=adj[s].end();i++)
  {
    if(visit[*i]==0)
    {
      dfs(*i,adj);
      visit[*i]=1;
    }
  }
}
 
main() 
{
   int v,e,a,b;
   cin>>v>>e;
   vector<int>adj[v+1];
   for(int i=0;i<e;i++)
   {
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
   }
   int select;
   cin>>select;
   dfs(select,adj);
}
  
 
 
