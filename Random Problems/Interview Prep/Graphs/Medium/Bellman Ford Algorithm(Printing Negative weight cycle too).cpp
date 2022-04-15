//https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1/?page=2&company[]=Microsoft&category[]=Graph&sortBy=submissions#
/*
Some points are written in notes also.

Bellman ford algo-
1.Take any order of the edges in the list.
2.Set distance of a every node from source as 1e8 except source node which will have distance 0.
3.Traverse all the edges one by one, and relax distance of v from source through the current edge(u,v).
4.Do the 3rd step N-1 times, where N is the total number of nodes.

Why it works?
Let us now prove the following assertion: 
After the execution of ith phase, the Bellman-Ford algorithm correctly finds all shortest paths whose number of edges does not exceed i.

In other words, for any vertex a,  let us denote the k number of edges in the shortest path to it.
According to this statement, the algorithm guarantees that after kth phase the shortest path for vertex a will be found.

Proof: Consider an arbitrary vertex a to which there is a path from the starting vertex v , and consider a shortest path to it which is (p0=v,p1,..,pk=a).. 
Before the first phase, the shortest path to the vertex p0=v was found correctly. During the first phase, the edge (p0,p1) has been checked by the algorithm, 
and therefore, the distance to the vertex p1 was correctly calculated after the first phase. During the second phase, the edge (p1,p2) has been checked by the algorithm, 
and therefore, the distance to the vertex p2 was correctly calculated after the second phase. 
Repeating this statement  times, we see that after phase the 
distance to the vertex pk=a  gets calculated correctly, which we wanted to prove.

Any shortest path cannot have more than n-1 edges because largest shortest path will contain n nodes which eventually means it will have n-1 edges.
Therefore, the algorithm sufficiently goes up to the(n-1)th phase. After that, it is guaranteed that no relaxation will improve the distance to some vertex.

TC - O(N*E)
SC - O(N)
*/
class Solution
{
	public:
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) 
    {
        vector<int>distance(V);
        int pre[V];
        for(int i=0;i<V;i++)distance[i]=1e8;
        distance[S]=0;
        //Running V times, so that if theres a cycle , we can print it
        int lastnode;
        for(int i=0;i<V;i++)
        {
          lastnode=-1;
         for(int j=0;j<adj.size();j++)
         {
            int node1=adj[j][0];
            int node2=adj[j][1];
            int wt=adj[j][2];
            if(distance[node1]+wt<distance[node2])
            {
                distance[node2]=distance[node1]+wt;
                lastnode=node2;
                pre[node2]=node1;
            }
         }
        }
        /*
        if(lastnode==-1)cout<<"No cycle";
        else 
        {
          //Traverse the predessesors from last node n times.After traversing
          //the last node traversed will belong to a cycle, because, during the
          //traversal, as soon as it enters the cycle, the nodes will be repeating inside
          //because, relaxation will happen among the nodes of the cycle.
          for(int i=0;i<n;i++)
          {
             lastnode=pre[lastnode];
          }
          //Now, lastnode is one of the nodes in a cycle, we will again traverse the predessors and save them , until we get back to same node from
          //which we started, which is "lastnode"
          vector<int>negcycle;
          int cur=lastnode;
          while(1)
          {
            negcycle.push_back(cur);
            if(pre[cur]==lastnode)break;
          }
          //we have got the reversed path, now reverse to get the 
          //sequential path of the negative weight cycle
          reverse(negcycle.begin(),negcycle.end());
          for(auto x: negcycle)cout<<x<<" ";
          
        }
        */
        
        return distance;
    }
};
