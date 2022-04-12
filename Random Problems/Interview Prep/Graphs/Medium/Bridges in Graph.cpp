//https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1/?page=1&company[]=Microsoft&category[]=Graph&sortBy=submissions#
class Solution
{
	public:
	int timer=1,result=-1;
    void bridge_dfs(int node, int parent, int *in_time, int *low_reachable, int *visit, vector<int> *adj, int c, int d)
    {
      for(int i=0;i<adj[node].size();i++)
      {
        int adjacent=adj[node][i];
        if(adjacent==parent)continue;
        if(visit[adjacent]==0)
        {
          timer++;
          in_time[adjacent]=timer;
          low_reachable[adjacent]=in_time[adjacent];
          visit[adjacent]=1;
          bridge_dfs(adjacent, node,in_time,low_reachable,visit, adj, c,d);
          
          low_reachable[node]=min(low_reachable[node],low_reachable[adjacent]);
          if((node==c && adjacent==d) || (node==d && adjacent==c))
          {
              if(low_reachable[adjacent]<=in_time[node])result=0;
              else result=1;
          }
        }
        else 
        {
          //back edge
          low_reachable[node]=min(low_reachable[node],in_time[adjacent]);
        }
      }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
      int in_time[V]={0}, low_reachable[V], visit[V]={0};
      for(int i=0;i<V;i++)
      {
        if(visit[i]==0)
        {
          in_time[i]=1;
          low_reachable[i]=0;
          visit[i]=1;
          timer=1;
          bridge_dfs(i,-1,in_time,low_reachable,visit,adj,c,d);
          if(result!=-1)break;
        }
      }
      if(result==-1)result=0;
      return result;
    }
};
