#include<bits/stdc++.h>
using namespace std;
int ans[100009],visit[100009];
int dfs(int n,int val,vector<pair<int,int>>g[])
{
  for(int i=0;i<g[n].size();i++)
  {
    int adj=g[n][i].first;
    if(visit[adj]==0)
    {
      visit[adj]=1;
      if(g[n].size()==2 && i>0)
      {
        if(ans[g[n][i-1].second]==2)val=3;
        else if(ans[g[n][i-1].second]==3)val=2;
      }
      ans[g[n][i].second]=val;
      if(val==2)dfs(adj,3,g);
      if(val==3)dfs(adj,2,g);
    }
  }
}
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    memset(ans,0,sizeof(ans));
    memset(visit,0,sizeof(visit));
    vector<pair<int,int>>g[n+1];
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
     int u,v;
     cin>>u>>v;
     g[u].push_back({v,i});
     g[v].push_back({u,i});
     if(g[u].size()>2 || g[v].size()>2)flag=1;
    }
    if(flag==1){cout<<-1<<endl;continue;}
    visit[1]=1;
    dfs(1,2,g);
    for(int i=0;i<n-1;i++)cout<<ans[i]<<" ";
    cout<<endl;

  }
}
/*1.Never overkill a problem.
 2.think of test cases to clarify the approach/doubts.
*/ 
