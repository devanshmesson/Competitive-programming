//if there are only unit weights, then just use a queue
//Read notes of 01 bfs in the copy
int zero_one_bfs(vector<pair<int,int>>g[], int n)
{
  deque<int>nodes;
  nodes.push_back(1);
  int distance[n+1];
  for(int i=2;i<=n;i++)distance[i]=INT_MAX;
  distance[1]=0;
  int visit[n+1]={0};
  while(nodes.size()>0)
  {
    int pick=nodes.front();
    nodes.pop_front();
    if(visit[pick]==1)continue;
    visit[pick]=1;
  
    //Relax the adjacent edges
    for(int j=0;j<g[pick].size();j++)
    {
      int adjacent=g[pick][j].first;
      int newdist=distance[pick]+g[pick][j].second;
      if(newdist<distance[adjacent])
      {
        distance[adjacent]=newdist;
        if(g[pick][j].second==1)nodes.push_back(adjacent);
        else nodes.push_front(adjacent);
      }
    }
  }
  return distance[n];
}
