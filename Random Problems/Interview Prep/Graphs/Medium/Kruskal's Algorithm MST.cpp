/*

*/
struct edge
{
  int u,v,weight;
  edge(int u_,int v_,int wt_)
  {
	u=u_;
	v=v_;
	weight=wt_;
  }
};
bool comp(edge a,edge b){return a.weight<b.weight;}
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(int node,int *parent)
	{  
	   if(parent[node]==node)return node;
	   int root=find(parent[node],parent);
	   //path compression -  making the root as the parent of the current node to reduce time complexity
	   return parent[node]=root;
	}
	bool do_union(int u, int v, int *parent, int *rank)
	{
	  int root1=find(u,parent);
	  int root2=find(v,parent);
	  if(root1==root2)return false;
	  //Union by rank
	  if(rank[root1]<rank[root2])parent[root1]=root2;
	  else if(rank[root1]>rank[root2])parent[root2]=root1;
	  else {parent[root1]=root2; rank[root2]++;}
	  return true;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //Just pushing the edges into a vector of "edge" class wich contains the edge weight and the two nodes associted with that edge.
        vector<edge>edges;
        for(int node=0;node<V;node++)
        {
          for(int i=0;i<adj[node].size();i++)
          {
             int adjacent=adj[node][i][0];
             int weight=adj[node][i][1];
             edge e(node,adjacent,weight);
             edges.push_back(e);
          }
        }
        //Soerting the edges on the basis of edge weights in increasing order, this is the first step in kruskal.
        sort(edges.begin(),edges.end(),comp);
        int parent[V], rank[V];
        for(int i=0;i<V;i++){parent[i]=i, rank[i]=0;}
        int cost=0;
        vector<pair<int,int>>mst;
        //Traversing each edge, if they dont belong to same set, that means you can add that edge.Otherwise, it makes a cycle, so we skip that edge.
        for(int i=0;i<edges.size();i++)
        {
          bool add_edge=do_union(edges[i].u,edges[i].v,parent,rank);
          //if add_edge is true,it means, that adding this edge will not make a cycle.Otherwise it will make, so skip it
          if(add_edge)
          {
             cost+=edges[i].weight;
             mst.push_back({edges[i].u,edges[i].v});
          }
        }
        /*
        To print the MST.
        for(int i=0;i<mst.size();i++)cout<<mst[i].first<<" "<<mst.second<<endl;
        */
        return cost;
    }
};
