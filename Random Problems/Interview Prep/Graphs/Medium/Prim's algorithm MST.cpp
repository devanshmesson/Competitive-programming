//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/#
/*
1.First find the source node having an edge with minimum weight.
2.Find the adjacent node(say, p) having minimum edge weight with source.The adjacent node should be not be visited earlier.
3.Now find the adjacent node(say ,q) having minimum edge weight with source or p.The adjacent node should be not be visited earlier.
4.Now find the adjacent node(say ,r) having minimum edge weight with source or p or r.The adjacent node should be not be visited earlier.
5. Do this until we have found all the n nodes of the graph.
This way a Minimum spanning tree will be made.

Intuition :
Find the minimum edge, then select one minimum edge among the edges coming out from both nodes.This way, we 
are keeping the tree connected as well as with min cost.

Used a priority queue(pq) for this.
1.First find the source node having an edge with minimum weight. Push the source along with cost into pq.
2.Now, Minimize its edge weights if possible, which means, if earlier some node has this edge with greater edge weight, so now
update the edge weight with the current one.Push this minimized edge weight along with node connected into pq.
3.Now,fetch the node with minimum edge weight and repeat.

TC - O(E*Log(N))
sc - O(N)
*/
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int key[V];
        //Visited array
        bool mst[V]={false};
        for(int i=0;i<V;i++)key[i]=INT_MAX;
        int mincost=INT_MAX,source;
        //Finding the source node having edge of minimum cost.
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                int adjacent=adj[i][j][0];
                int wt=adj[i][j][1];
                if(mincost>wt)
                {
                    mincost=wt;
                    source=i;
                }
            }
        }
        //No edge included so, cost=0 for source.
        key[source]=0;
        //Pushed edge cost along with node.
        pq.push({0,source});
        //For saving MST
        int parent[V];
        parent[source]=-1;
        int cost=0;
        while(!pq.empty())
        {
          //Fetching the edge having minimum cost.
          int node=pq.top().second;
          int weight=pq.top().first;
          pq.pop();
          if(mst[node])continue;
          mst[node]=true;
          cost+=weight;
          //Minimizing the edge cost to adjacent nodes
          for(int i=0;i<adj[node].size();i++)
          {
             int adjacent=adj[node][i][0];
             int wt=adj[node][i][1];
             if(key[adjacent]>wt)
             {
                 key[adjacent]=wt;
                 pq.push({wt,adjacent});
                 parent[adjacent]=node;
             }
             
          }
        }
        /*To print the MST
        for(int i=0;i<V;i++)
        {
            if(parent[i]==-1)continue;
            cout<<i<<" "<<parent[i]<<endl;
        }
        */
        return cost;
    }
};  
