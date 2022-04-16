//https://leetcode.com/problems/number-of-islands/
/*
Performed BFS.
This problem is basically count connected components.
So, we have to find connected lands(represented by 1) in the matrix.
We can go left,right,up,down to travel from one land to adjacent land.
So, just run bfs from each land and visit all the adjacent lands possible, and increment island counter once 
before a new BFS call starts.

Intuition : The area other than connected lands is water so, automatically connected lands are surrounded by water.

TC - O(M*N + M*N) In total, BFS will run M*N times
SC - O(M*N)


*/
class Solution 
{
public:
    int rows,cols;
    bool check(int i,int j)
    {
      if(i>=0 && j>=0 && i<rows && j<cols)return true;
      return false;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
      rows=grid.size(), cols=grid[0].size();
      int visit[rows][cols];
      for(int i=0;i<rows;i++)for(int j=0;j<cols;j++)visit[i][j]=0;
      int islands=0;
      vector<pair<int,int>>directions={{0,-1},{0,1},{-1,0},{1,0}};
      for(int i=0;i<rows;i++)
      {
        for(int j=0;j<cols;j++)
        {
          if(visit[i][j]==0 && grid[i][j]=='1')
          {
            visit[i][j]=1;
            islands++;
            //bfs to left,right,up,down
            queue<pair<int,int>>q;
            q.push({i,j});
            while(!q.empty())
            {
              int x=q.front().first, y=q.front().second;
              q.pop();
              //left i,j-1
              //right i,j+1
              //up i-1,j
              //down i+1,j
              for(int k=0;k<4;k++)
              {
                int new_row=x+directions[k].first;
                int new_col=y+directions[k].second;
                
                if(check(new_row,new_col) && visit[new_row][new_col]==0 && grid[new_row][new_col]=='1')
                {
                  visit[new_row][new_col]=1;
                  q.push({new_row,new_col});
                }
              }
            }  
          }
        }
      }
      return islands;
    }
};
