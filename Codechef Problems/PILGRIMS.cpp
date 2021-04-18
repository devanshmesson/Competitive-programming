#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

 vector<pair<int,int>>adj[100005];
 vector<int>special,visit(100005,0);

int dfs(int n,int dist,int cnt)
{
  for(auto x:adj[n])
  {
    int node=x.first;
    int wt=x.second;
    int d=cnt*wt;
    d+=dist;
    if(visit[node]==0)
      {
        visit[node]=1;
        dfs(node,d,cnt+1);
      }
  }
  if(adj[n].size()==1 && n!=1)
    {
      special.pb(dist);
    }
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    special.clear();
    for(int i=0;i<=n;i++)adj[i].clear();
    int a[m+1];
    for(int i=0;i<m;i++)cin>>a[i];
   
    
    int u,v,w;

    for(int i=0;i<n-1;i++)
    {
     cin>>u>>v>>w;
     adj[u].pb({v,w});
     adj[v].pb({u,w});
    }
    
    for(int i=0;i<100005;i++)visit[i]=0;
    visit[1]=1;
    dfs(1,0,1);
    
    sort(special.begin(),special.end());
    sort(a,a+m);
    int sz=special.size();

    int worker=0,home=0;
    int ans=0;
    vector<int>vi(m+1,0);
    int index=-1;
   for(int i=0;i<sz;i++)
   {
    for(int j=index+1;j<m;j++)
    {
      if(a[j]>=special[i] && vi[j]==0)
        {
          ans++;
          vi[j]=1;
          index=j;
          break;
        }
    }
   }

    cout<<ans<<endl;


  }
}
