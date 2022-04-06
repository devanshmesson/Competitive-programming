//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/*
Why the solution of undirected graph will not work here?
Because In undirected graph, we can reach to all nodes from any starting node in a particular connected component.
So, Detecting whether there is a cycle or not, is easy. But in directed graph, we cant reach to
all nodes from any starting node. If we apply the undirected solution to this problem, then
It may return true stating that there is a cycle even if there is not.This is because. If there is no cycle,
it will reach till the last node, so all nodes in this path will get visited. Problem occurs when they backtrack.
Because, when they backtrack, values of visited array remains same. So, while backtracking if there is a node(say p), from
which path has not traversed,DFS will start moving on this path,and if it founds a visited node(say v), 
it will say that, graph contains a cycle, but its not. Had been there a cycle, then from v(the moment when DFS was at v) 
we could have reached p and then & there we would have returned true, but it got backtracked, that means, there was no cycle.

Cycle should be detected only in the same DFS call. For example, if we are standing at node x.Then from x, we should 
discover a node p which is visited. If from, bactracking occurs, that means, no cycle was there from x.

So, solution to this is, that if a node(say, v) is backtracking,that means it did not found any cycle. Or we can say, that
this node is not a part of a cycle in the graph.Had been there a cycle, it would have returned true.
So, we will change the value of visit[node] to 2. Here value=2 signifies, that this node will not be counted as
visited in this current dfs function for a particular connected component.But this node is counted as visited overall in the graph. which 
means, we will not start a dfs again from this node from the for loop.

TC - O(N+E)
SC - O(N) + O(N)
visit array + auxiliary recursion space.
*/
class Solution  
{
  public:
    int dfs(int node,int *visit,vector<int> *adj)
    {
      for(int i=0;i<adj[node].size();i++)
      {
        int adjacent=adj[node][i];
        if(visit[adjacent]==0)
        {
          visit[adjacent]=1;
          bool iscyclic=dfs(adjacent,visit,adj);
          if(iscyclic)return true;
        }
        else if(visit[adjacent]==1) return true;
      }
      visit[node]=2;
      return false;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
      int visit[V]={0};
      for(int i=0;i<V;i++)
      {
        if(visit[i]==0)
        {
          visit[i]=1;
          if(dfs(i,visit,adj))return true;
        }
      }
      return false;
    }
};
