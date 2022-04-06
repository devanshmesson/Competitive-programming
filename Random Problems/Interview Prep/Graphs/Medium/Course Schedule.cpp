//https://leetcode.com/problems/course-schedule/

/*
This problem asks us to find whether we can find a topological sorting for the graph or not.Graph will be made
such that, if course u is a pre-requisite for course v,then there should an edge between course u to course v.

Topological sorting cannot be found out if the graph is a cyclic.Otherwise, there is always a topological sorting.
So, if graph contains a cycle, then return false.Otherwise, true.

Performed DFS.

TC - O(N+E)
SC- O(N+E)+O(N)
Auxiliary space - O(N)
*/
class Solution 
{
public:
    int dfs(int node,int *visit, vector<int> *adj)
    {
        for(int i=0;i<adj[node].size();i++)
        {
          int adjacent=adj[node][i];
          if(visit[adjacent]==0)
          {
             visit[adjacent]=1;
             if(dfs(adjacent,visit,adj))return true;
          }
          else if(visit[adjacent]==1)return true;
        }
        visit[node]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {  
          int u=prerequisites[i][0];
          int v=prerequisites[i][1];
          adj[v].push_back(u);
        }
        int visit[numCourses];
        for(int i=0;i<numCourses;i++)visit[i]=0;
        for(int i=0;i<numCourses;i++)
        {
          if(visit[i]==0)
          {
             visit[i]=1;
             if(dfs(i,visit,adj))return false;
          }
        }
        return true;
    }
};
