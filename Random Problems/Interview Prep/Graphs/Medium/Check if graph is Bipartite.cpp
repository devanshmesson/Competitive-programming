//https://practice.geeksforgeeks.org/problems/bipartite-graph/1/

/*
Approach- BFS
A bipartite graph is a graph which can be colored using 2 colors such that no adjacent nodes have same color.
Why adjacent nodes? because adjacent nodes have an edge between them, so bipartite graph splits nodes in two sets, where adjacent nodes are in different sets.

If There is a cycle of odd length(i.e. having odd number of nodes) in the graph, then that graph is not bipartite.
why?
Visualize the cycle as a circular below
cycle 1->2->3->4->5  (1 is connected to 5)
coloured cycle 1 2 1 2 1  (nodes 1 and 5 have same colour that means 1 and 5 are in same sets, which is a violation)

If There is a cycle of even length(i.e. having even number of nodes) in the graph, then that graph is bipartite.
why?
Visualize the cycle as a circular below
cycle 1->2->3->4->5->6  (1 is connected to 6)
coloured cycle 1 2 1 2 1 2 (all adjacent nodes have different color, so its bipartite)


Perform a BFS, on every component of the graph, If a node is coloured 1, color the adjacent nodes with 2 (if they are not coloured).
If adjacent node is already coloured, then check if the current node and adjacent node have same color.If yes, then its not a bipartite
graph.

if we did not find any violation, that means, graph is bipartite.

TC - O(N+E)
SC - O(N+E)
*/
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    int color[V]={0};
	    for(int i=0;i<V;i++)
	    {
	     if(color[i]==0)
	     {
	      queue<int>q;
	      q.push(i);
	      color[i]=1;
	      while(!q.empty())
	      {
	        int node=q.front();
	        q.pop();
	        for(auto adjacent: adj[node])
	        {
	          if(color[adjacent]==0)
	          {
	              color[adjacent]=(color[node]==1)?2:1;
	              q.push(adjacent);
	          }
	          else if(color[adjacent]==color[node])return false;
	        }
	      }
	     }
	    }
	    return true;
	}

};
