//No problem link 
/*
This problem, can be solved through BFS too.But there will be too many redundancies in it.
We start from source=0, it relaxes its adjacents, and pushes these adjacent nodes along with their distances into the queue.
Then these adjacent nodes will further relax their adjacent nodes and push the relaxed nodes.

Consider this graph:

1->(2,2)
1->(3,1)
2->(4,2)
3->(5,1)
5->(4,1)
4->(6,1)

Final queue will be like - (first of pair is the node and second of pair is the distance from source to this node)
(1,0)(2,2)(3,1)(4,4)(5 2)(6 5)(4 3)(6 4)
These all will be popped out when they relax their adjacent nodes.
For ex, (1,0) will be popped out before (2,2)(3,1) are pushed into queue and so on.

As we can see, there is redundancy, node 4 first came in the queue with a distance of 4 from source, and then again
node 4 came with a distance of 3 from the source, which increases time complexity, because, now (4,3) will have to again relax its adjacent nodes
to reduce the distances of its adjacent nodes.

So, if the pre-requisites of any node(say, cur) are relaxed as minimum as possible before the relaxation of node cur.Then
redundancy will never occur.
Taking the same example as above, if 1 2 3 5 are relaxed as minimum as possible before the relaxation of node 4. Then 
redundancy will never occur.

The solution to the above observation is Topological sort.
If we have Topo sort sequence, then we will take the source node first and relax its adjacent nodes.After that, we take next node
in the topo sort, and will do the same.

TC - O(N+E)
SC-O(N)
*/


class Solution
{
	public:
	int dfs(int node,int *visit,stack<int>&tp, vector<pair<int,int>> *adj)
	{
	    for(int i=0;i<adj[node].size();i++)
	    {
	       if(visit[i]==0)
	       {
	           visit[i]=1;
	           dfs(node,visit,tp,adj);
	       }
	    }
	    tp.push(node);
	}
	vector<int> topoSort(int V, vector<pair<int,int>>adj[]) 
	{
	   //first of pair is adjacent node, second of pair is edge between node and its adjacent
	   stack<int>tp;
	   int visit[V]={0};
	   for(int i=0;i<V;i++)
	   {
	    if(visit[i]==0)
	    {
	       visit[i]=1;
	       dfs(i,visit,tp,adj);
	    }
	   }
	   int distance[V];
	   for(int i=0;i<V;i++)distance[i]=INT_MAX;
	   distance[0]=0;
	   
	   while(!tp.empty())
	   {
	     int node=tp.top();
	     tp.pop();
	     //relax the adjacent nodes
	     for(int i=0;i<adj[node].size();i++)
	     {
	       int adjnode=adj[node][i].first;
	       int newdist=distance[node]+adj[node][i].second;
	       if(newdist<distance[adjnode])distance[adjnode]=newdist;  
	     }
	   }
	   
	}
};
