#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl "\n"

vector<int>visit(50001),path;
int edge;
vector<pair<int,int>>adj[100001];

void dfs(int n,int edge)
{
  for(auto x:adj[n])
  {
    if(visit[x.first]==0)
      {
        visit[x.first]=1;
        dfs(x.second,x.first);
      }
  } 
  if(edge!=0)path.pb(edge);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,m,a,b;
      cin>>n>>m;
      path.clear();
      for(int i=1;i<=m;i++){visit[i]=0;}
      for(int i=0;i<=(2*n);i++)adj[i].clear();
      
      for(int i=1;i<=m;i++)
      {
        cin>>a>>b;
        b+=n;
        adj[a].pb({i,b});
        adj[b].pb({i,a});
      }
      int node;
      for(int i=1;i<=2*n;i++)
      {
        if(adj[i].size()%2==0 && adj[i].size()>0){node=i;}
        if(adj[i].size()%2==1){node=i;break;}
      }
      dfs(node,0);
      reverse(path.begin(),path.end());
      for(auto x:path)cout<<x<<" ";
      cout<<endl;
    }
}
