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

/*
Performed BFS(Kahn's algorithm).
Observation 1 - if there a node u, who is an adjacent node of nodes x,y,z.In other words,
x,y,z are pre-requisites for node u.If these x y z are already included in the topological sort
then, that means pre-requites for node u are done, so node u can now be included in the topo sort.

Observation 2 - First node of Topological sort has no pre-requisite.In other words, it has 0 indegree.

An indegree of a node defines it's number of pre-requites.So we will calculate indegree of each node 
in the graph and the nodes with 0 indegree will be present at the beginning of the topo sort.

Nodes with 0 indegree will start the BFS, so they all are pushed into the queue.Indegree of
adjacent nodes of current node in the bfs will be reduced by 1.Reducing by 1 is signifying 
that a pre-requisite of adjacent node is present in the topo sort.If Indegree of
adjacent nodes of current node becomes 0, that means, all pre-requisites for this node
are present in the topo sort.So, now this adjacent node can enter into toposort.So, push this adjacent
node into the queue.

So, we are adding those nodes in the toposort whose pre-requites are completed.

TC - O(N+E)
SC - O(N)
*/
class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   queue<int>tp;
	   int indegree[V]={0};
	   for(int i=0;i<V;i++)
	   {
	     for(int j=0;j<adj[i].size();j++)indegree[adj[i][j]]++;
	   }
	   for(int i=0;i<V;i++)if(indegree[i]==0)tp.push(i);
	   vector<int>toposort;
       while(!tp.empty())
       {
          int node=tp.front();
          toposort.push_back(node);
          tp.pop();
          for(int i=0;i<adj[node].size();i++)
          {
              int adjacent=adj[node][i];
              indegree[adjacent]--;
              if(indegree[adjacent]==0)
              {
                  tp.push(adjacent);
              }
          }
       }
       return toposort;
	}
};
