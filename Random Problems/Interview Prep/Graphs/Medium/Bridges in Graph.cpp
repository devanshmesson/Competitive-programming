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
        //If adjacent node is a parent node, then nothing needs to be done, because parent cant be the lowest reachable ancestor of its child.
        if(adjacent==parent)continue;
        if(visit[adjacent]==0)
        {
          //Increments timer as we visit an unvisited node
          timer++;
          //Assign in time of the child node as timer, and assign lowest reachable ancestor as itself
          low_reachable[adjacent]=in_time[adjacent]=timer;
          visit[adjacent]=1;
          bridge_dfs(adjacent, node,in_time,low_reachable,visit, adj, c,d);
          //If child node has a back edge to any ancestor, or in other words, if child has a lowest reachable ancestor,
          //Then that means parent also have access to this ancestor, child node is in the subtree of its parent.
          //If Parent has access to its ancestor which is already lower, then dont change.
          low_reachable[node]=min(low_reachable[node],low_reachable[adjacent]);
          //Because child node has found its lowest reachable ancestor(if any), then find that 
          //if this edge(node,adjacent) is a bridge or not. If there is a node in the subtree of child that has access to
          //"node" or its ancestor, then its not a bridge.Otherwise it is.
          if((node==c && adjacent==d) || (node==d && adjacent==c))
          {
              if(low_reachable[adjacent]<=in_time[node])result=0;
              else result=1;
          }
        }
        else 
        {
          //If the adjacent node is visited, that means this adjacent node is an ancestor of "node",
          //So, update the lowest reachable ancestor. If the node already has the lowest then dont change.
          low_reachable[node]=min(low_reachable[node],in_time[adjacent]);
        }
      }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
      int in_time[V]={0}, low_reachable[V], visit[V]={0};
      //Checking for each connected component
      for(int i=0;i<V;i++)
      {
        if(visit[i]==0)
        {
          //Root node has in time of 1
          in_time[i]=1;
          //Initially, Root node's lowest reachable ancestor is itself.
          low_reachable[i]=i;
          visit[i]=1;
          //Timer will start from 2, because first it increments and then it assigns.
          timer=1;
          bridge_dfs(i,-1,in_time,low_reachable,visit,adj,c,d);
          //If c and d are found, that means result variable will change so, so further dfs is needed
          if(result!=-1)break;
        }
      }
      //If edge(c,d) does not exists, there is no bridge.
      if(result==-1)result=0;
      return result;
    }
};
