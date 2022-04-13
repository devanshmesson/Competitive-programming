//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/
class Solution
{
	public:
	vector<int>toposort;
	void dfs(int node, int *visit, vector<int> *adj, int flag)
	{
	   for(int i=0;i<adj[node].size();i++)
	   {
	       int adjacent=adj[node][i];
	       if(visit[adjacent]==0)
	       {
	           visit[adjacent]=1;
	           dfs(adjacent,visit,adj,flag);
	       }
	   }
	   if(flag==1)toposort.push_back(node);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>transpose[V];
        for(int i=0;i<V;i++)
        {
         for(int j=0;j<adj[i].size();j++)
         {
            int adjacent=adj[i][j];
            transpose[adjacent].push_back(i);
         }
        }
        int visit[V]={0};
        for(int i=0;i<V;i++)
        {
         if(visit[i]==0)
         {
           visit[i]=1;
           dfs(i,visit,adj,1);
         }
        }
        for(int i=0;i<V;i++)visit[i]=0;
        int scc=0;
        for(int i=V-1;i>=0;i--)
        {
          int node=toposort[i];
          if(visit[node]==0)
          {
              visit[node]=1;
              dfs(node,visit,transpose,0);
              scc++;
          }
        }
        return scc;
        
    }
};
