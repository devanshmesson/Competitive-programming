//https://practice.geeksforgeeks.org/problems/topological-sort/1

/*
Performed DFS.
Used stack. Why?
Suppose the dfs traversal is like : u->v->x->y
Our Toposort should be u v x y. Which means y should be pushed into stack first,
Then x, then v and then u.

Since stack uses LIFO structure.So, if we push the nodes in the order from last traversed node to first traversed node.then
first traversed node will be on top, then second traversed node,etc and the last node will be at bottom.So, stack will contain a 
topological sort from its top to its bottom.

TC - O(N+E)
SC - O(N)
Auxiliary space - O(N)
*/
class Solution
{
	public:
	void dfs(int node,int *visit, vector<int> *adj, stack<int>&tp)
	{
	    for(int i=0;i<adj[node].size();i++)
	    {
	        int adjacent=adj[node][i];
	        if(visit[adjacent]==0)
	        {
	            visit[adjacent]=1;
	            dfs(adjacent,visit,adj,tp);
	        }
	    }
	    tp.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	  stack<int>tp;
	  int visit[V]={0};
	  for(int i=0;i<V;i++)
	  {
	     if(visit[i]==0)
	     {
	       visit[i]=1;
	       dfs(i,visit,adj,tp);
	     }
	  }
	  vector<int>toposort;
	  while(!tp.empty())
	  {
	    toposort.push_back(tp.top());
	    tp.pop();
	  }
	  return toposort;
	}
};
