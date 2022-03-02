// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

int zero_one_bfs(vector<pair<int,int>>g[], int n)
{
  deque<pair<int,int>>nodes;
  nodes.push_back({0,1});
  int distance[n+1];
  for(int i=2;i<=n;i++)distance[i]=INT_MAX;
  distance[1]=0;
  
  int visit[n+1]={0};


  while(nodes.size()>0)
  {
    pair<int,int>p=nodes.front();
    int pick=p.second;
    int dist=p.first;
    nodes.pop_front();
    if(visit[pick]==1)continue;
    visit[pick]=1;
  
    //Relax the adjacent edges
    for(int j=0;j<g[pick].size();j++)
    {
      int adjacent=g[pick][j].first;
      int newdist=dist+g[pick][j].second;
      if(newdist<distance[adjacent])
      {
        distance[adjacent]=newdist;
        if(g[pick][j].second==1)nodes.push_back({distance[adjacent],adjacent});
        else nodes.push_front({distance[adjacent],adjacent});
      }
    }
  }
  return distance[n];
}



signed main()
{
  freopen
  ios

  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n+1];
    if(m==0){cout<<n-1<<endl; continue;}
    

    int isedge[n+2]={0};
    for(int i=0;i<m;i++)
    {
      int u,v;
      cin>>u>>v;
      if(abs(u-v)==1)
      {
        isedge[min(u,v)]=1;
      }
      g[u].pb({v,0});
      g[v].pb({u,0});
    }

    for(int i=1;i<n;i++)
    {
      if(isedge[i]==0)
      {
        g[i].pb({i+1,1});
        g[i+1].pb({i,1});
      }
    }

    cout<<zero_one_bfs(g,n)<<endl;
  }
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
