//https://practice.geeksforgeeks.org/problems/articulation-point2616/1/#

/*
Idea is same as bridges.
A node(v) is an articulation point iff, in atleast one subtree of v, there is no node which has a back edge connecting to ancestor of v.
A node(v) is not an articulation point iff, in all subtrees of v, there is a node which has a back edge connecting to ancestor of v due to which
the graph stays connected.

One corner case - The lowest reachable ancestor will always be <= in time of root of graph, so If the node is a root of the graph, 
and it has only subtree, then root is not an articulation point.If root has more than one subtrees,then root is articulation point.

TC- O(N+E)
SC - O(N)


*/
class Solution 
{
  public:
    vector<int>ans;
    int timer;
    void dfs(int node, int parent, int *visit,int *in_time, int *low_reachable, vector<int> *adj, int *included)
    {
        int children=0;
        for(int i=0;i<adj[node].size();i++)
        {
          int adjacent=adj[node][i];
          if(adjacent==parent)continue;
          if(visit[adjacent]==0)
          {
            children++;
            timer++;
            visit[adjacent]=1;
            low_reachable[adjacent] = in_time[adjacent]=timer;
           
            dfs(adjacent, node,visit, in_time, low_reachable, adj, included);
            if(low_reachable[adjacent]>=in_time[node] && included[node]==0 && parent!=-1)
            {
              ans.push_back(node);
              included[node]=1;
            }
            low_reachable[node]=min(low_reachable[node],low_reachable[adjacent]);
          }
          else
          {
             low_reachable[node]=min(low_reachable[node],in_time[adjacent]);
          }
        }
        if(parent==-1 && children>1)ans.push_back(node);
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) 
    {
     int in_time[V], low_reachable[V], visit[V]={0}, included[V]={0};
     for(int i=0;i<V;i++)
     {
      if(visit[i]==0)
      {
          visit[i]=1;
          low_reachable[i]=in_time[i]=1;
          timer=1;
          dfs(i,-1,visit,in_time,low_reachable,adj,included);
      }
     }
     if(ans.size()==0)return {-1};
     sort(ans.begin(),ans.end());
     return ans;
    }
};
