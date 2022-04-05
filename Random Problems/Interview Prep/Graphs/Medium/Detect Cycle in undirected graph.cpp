//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

/*
DFS Approach:
Perform a dfs traversal, If the graph is disconnected, then do a dfs from all the unvisited nodes.
If in the dfs, you find adjacent node as visited and if this adjacent node is the not the node from which you came from.In other words,
if this adjacent node is not the "just" previous node in the traversal, then there is a cycle in the graph.You return true to the
calling function, this calling function return trwe to it calling function and finally it will return to the base calling funtion.

If there is no cycle found, so after for loop we will return false.
*/
class Solution 
{
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
      int visited[V]={0};
      vector<int>dfs;
      stack<int>s;
      s.push(0);
      while(!s.empty())
      {
       int node=s.top();
       if(visited[node]==0)
        {
         dfs.push_back(node);
         visited[node]=1;
        }
       s.pop();
       for(int i=adj[node].size()-1;i>=0;i--)
       {
           int adjacent=adj[node][i];
           if(visited[adjacent]==0)
           {
              s.push(adjacent);
           }
       }
      }
      return dfs;
    }
};
