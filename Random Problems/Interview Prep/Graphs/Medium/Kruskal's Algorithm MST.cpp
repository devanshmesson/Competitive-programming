//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
/*
Kruskal is a algorithm which finds the MST for a given graph.
Kruskal Algorithm -
1.Sort all edges according to weights in increasing order.
2.Traverse the sorted edges and starting making MST by adding the edges.
3.Before adding the edges, make sure to check if this edge will make a cycle or not.
4.If it makes a cycle then skip it, if not, add it and add the cost to a variable.
5.Do this until all the edges are traversed.

When N-1 edges will be added, rest of the edges will make a cycle, we will not add them.

Disjoint set union data structure is used to find whether an edge will make cycle or not.
If two nodes are already in the same set, then that means the edge will creat a cycle, because
If they are already in the set, that means a unique path exists already between
the two nodes that are associated with that particular edge and if we directly add that edge,
then two different paths will be there between those two nodes, which will make it a cycle.
Since MST is a tree, we dont want cycles. thats why we are checking this.



TC - O(M*LogM) + O(M * O(4*ALPHA)) = O(M*LogM) [Sorting the edges]
O(4*ALPHA) is a constant.
M means number of edges.

SC - O(M)+O(N)
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
