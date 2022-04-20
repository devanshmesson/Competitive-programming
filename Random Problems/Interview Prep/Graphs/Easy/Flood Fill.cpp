//https://leetcode.com/problems/flood-fill/submissions/
/*
Performed BFS.
If the adjacent cell has same color as the starting cell, then paint it.
TC - O(N*M)
SC - O(N*M)
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        queue<pair<int,int>>q;
        int rows=image.size();
        int cols=image[0].size();
        q.push({sr,sc});
        vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        int startcolor=image[sr][sc];
        image[sr][sc]=newColor;
        while(!q.empty())
        {
          int x=q.front().first;
          int y=q.front().second;
          q.pop();
          for(int i=0;i<direction.size();i++)
          {
             int newx=x+direction[i].first;
             int newy=y+direction[i].second;
             if(newx>=0 && newy>=0 && newx<rows && newy<cols  && image[newx][newy]==startcolor && image[newx][newy]!=newColor)
             {
               image[newx][newy]=newColor;
               q.push({newx,newy});
             }
          }
        }
        return image;
    }
};
