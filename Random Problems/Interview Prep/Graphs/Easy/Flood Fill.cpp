//https://leetcode.com/problems/flood-fill/submissions/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        queue<pair<int,int>>q;
        int rows=image.size();
        int cols=image[0].size();
        vector<vector<int>>filled(rows,vector<int>(cols));
        q.push({sr,sc});
        vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        filled[sr][sc]=1;
        int startcolor=image[sr][sc];
        while(!q.empty())
        {
          int x=q.front().first;
          int y=q.front().second;
          q.pop();
          for(int i=0;i<direction.size();i++)
          {
             int newx=x+direction[i].first;
             int newy=y+direction[i].second;
             if(newx>=0 && newy>=0 && newx<rows && newy<cols && filled[newx][newy]==0 && image[newx][newy]==startcolor)
             {
               filled[newx][newy]=1;
               q.push({newx,newy});
             }
          }
        }
        for(int i=0;i<rows;i++)
        {
         for(int j=0;j<cols;j++)
         {
           if(filled[i][j]==1)image[i][j]=newColor;
         }
        }
        return image;
    }
};
