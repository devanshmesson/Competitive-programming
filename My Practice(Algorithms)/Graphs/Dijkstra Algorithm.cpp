int dijkstra(vector<pair<int,int>>g[], int n)
{
  set<pair<int,int>>nodes;
  nodes.insert({0,1});
  int distance[n+1];
  for(int i=2;i<=n;i++)distance[i]=INT_MAX;
  distance[1]=0;
  


  for(int i=1;i<=n;i++)
  {
    pair<int,int>p=*(nodes.begin());
    int pick=p.second;
    int dist=p.first;
    
    nodes.erase(nodes.begin());

  
    //Relax the adjacent edges
    for(int j=0;j<g[pick].size();j++)
    {
      int adjacent=g[pick][j].first;
      int newdist=dist+g[pick][j].second;
      if(newdist<distance[adjacent])
      {
        if(nodes.count({distance[adjacent],adjacent}))nodes.erase({distance[adjacent],adjacent});
        distance[adjacent]=newdist;
        nodes.insert({newdist,adjacent});
      }
      
    }
  }
  return distance[n];
}
