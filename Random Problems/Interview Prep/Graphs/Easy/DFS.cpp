//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/#

//Recursive
class Solution 
{
  public:
    void printdfs(int node, vector<int> *adj,vector<int> &dfs,int *visited)
    {
        dfs.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            int adjacent=adj[node][i];
            if(visited[adjacent]==0)
            {
                visited[adjacent]=1;
                printdfs(adjacent,adj,dfs,visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
      int visited[V]={0};
      visited[0]=1;
      vector<int>dfs;
      printdfs(0,adj,dfs,visited);
      return dfs;
    }
};

//Iterative
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
         //we have to print the node which was recently added.
         //This node might be in the stack before too, but because 
         //we are doing a dfs, we have to explore as far as possible
         //and print the node recently added, so then we will consider it as visited.
         visited[node]=1;
        }
       s.pop();
       //To perform dfs Left to Right, stack will fill elements from right to left
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
