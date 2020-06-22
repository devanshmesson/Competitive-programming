#include<bits/stdc++.h>
using namespace std;

map<int,int>visit;
queue<int>q;

int bfs(int s,vector<int>adj[])
{
  vector<int>::iterator i;
  q.push(s);
  while(!q.empty())
  {
    int tp=q.front();
    if(visit[tp]==0)cout<<tp<<endl;
    visit[tp]=1;
    q.pop();

    for(i=adj[tp].begin();i!=adj[tp].end();i++)
    {
      if(visit[*i]==0){cout<<*i<<endl;visit[*i]=1;q.push(*i);}
    }
  }
return 0;
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
   bfs(select,adj);
} 
