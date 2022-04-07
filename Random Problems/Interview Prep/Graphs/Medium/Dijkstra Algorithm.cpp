//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
//Explanation in notes
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>distance(V);
        for(int i=0;i<V;i++)distance[i]=INT_MAX;
        distance[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        int mark[V]={0};
        while(!pq.empty())
        {
          int pick=pq.top().second;
          pq.pop();
          if(mark[pick]==1)continue;
          mark[pick]=1;
          for(int i=0;i<adj[pick].size();i++)
          {
              int adjacent=adj[pick][i][0];
              int newdist=distance[pick]+adj[pick][i][1];
              //relaxing
              if(newdist<distance[adjacent])
              {
                  distance[adjacent]=newdist;
                  pq.push({newdist,adjacent});
              }
          }
        }
        return distance;
    }
};
