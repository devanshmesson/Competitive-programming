/*
Resources - 
1.https://youtu.be/JpapV5DrBek
2.https://www.youtube.com/watch?v=gbasc4F-7hk 
3.https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
*/

/*
Kuhn algorithm solves this problem - 
You are given a bipartite graph  containing  vertices and  edges. Find the maximum 
matching, i.e., select as many edges as possible so that no selected edge shares a 
vertex with any other selected edge.
*/
#include<bits/stdc++.h>
using namespace std;

//Kuhn algorithm is used to maximize the pairs that can be matched with each other.
//Pair contains, one vertex from 1st set and 1 vertex from 2nd set.
//One vertex can be matched with only one vertex.

int kuhn_algo(int n,vector<int>graph[],int mappedto[],int visit[])
{
  if(visit[n]==1)return 0;
  visit[n]=1;
  for(int i=0;i<graph[n].size();i++)
  {
    int adj=graph[n][i];
    if(mappedto[adj]==-1){mappedto[adj]=n; return 1;}
    int approval=kuhn_algo(mappedto[adj],graph,mappedto,visit);  //mappedto[adj] got linked with other vertex, so adj can be linked to n
    if(approval==1)
    {
      mappedto[adj]=n; 
      return 1;
    }
  }
  return 0;
}
signed main()
{
  int nodes,edges;
  cin>>nodes>>edges;
  vector<int>graph[nodes+1];
  int mappedto[nodes+1];
  int visit[nodes+1];
  memset(mappedto,-1,sizeof(mappedto));
  for(int i=0;i<edges;i++)
  {
    //u belongs to 1st set, v belongs to 2nd set
    int u,v;
    cin>>u>>v;
    //building bipartite graph
    graph[u].pb(v);
  }
  for(int i=0;i<nodes;i++)
  {
    if(graph[i].size()==0)continue;
    memset(visit,0,sizeof(visit));
    int cnt=kuhn_algo(i,graph,mappedto,visit);
  }
  //mappedto[i] is a vertex from 1st set, i belong to 2nd set
  for(int i=0;i<nodes;i++)cout<<i<<" mapped to:"<<mappedto[i]<<endl;
}
