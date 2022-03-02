int zero_one_bfs(vector<pair<int,int>>g[], int n)
{
  deque<pair<int,int>>nodes;
  nodes.push_back({0,1});
  int distance[n+1];
  for(int i=2;i<=n;i++)distance[i]=INT_MAX;
  distance[1]=0;
  
  int visit[n+1]={0};


  for(int i=1;i<=n;i++)
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
