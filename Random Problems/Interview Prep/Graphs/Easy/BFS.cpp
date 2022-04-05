//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/#
class Solution 
{
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
       int visited[V]={0};
       vector<int>bfs;
       queue<int>q;
       q.push(0);
       visited[0]=1;
       while(!q.empty())
       {
        int node=q.front();
        bfs.push_back(node);
        q.pop();
        for(auto x: adj[node])
        {
          if(visited[x]==0)
          {
            q.push(x);
            visited[x]=1;
          }
        }
       }    
       return bfs;
    }
};
