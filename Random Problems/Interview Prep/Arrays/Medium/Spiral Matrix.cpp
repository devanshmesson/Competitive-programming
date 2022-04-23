//https://leetcode.com/problems/spiral-matrix/
/*
ith row                     (i+1)th row    
mth col                     (m-1)th col
nth row (reverse)           (n-1)th row (reverse)
ith col (reverse)           (i+1)th row (reverse)

and so on.

TC - (Rows * Columns)
SC - O(1)
*/
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int top=0,bottom=rows-1,left=0,right=cols-1;
        int direction=0;
        vector<int>spiral;
        while(top<=bottom && left<=right)
        {
          if(direction==0)
          {
            for(int i=left;i<=right;i++)spiral.push_back(matrix[top][i]);
            top++;
          }
          else if(direction==1)
          {
            for(int i=top;i<=bottom;i++)spiral.push_back(matrix[i][right]);
            right--; 
          }
          else if(direction==2)
          {
            for(int i=right;i>=left;i--)spiral.push_back(matrix[bottom][i]);
            bottom--;
          }
          else if(direction==3)
          {
            for(int i=bottom;i>=top;i--)spiral.push_back(matrix[i][left]);
            left++;
          }
          direction=(direction+1)%4;
        }
          return spiral;
            
        
        
    }
};
