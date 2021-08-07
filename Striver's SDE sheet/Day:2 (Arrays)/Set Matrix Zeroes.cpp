class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
       int rowsize=matrix[0].size(),colsize=matrix.size();
       int dummyrow0=1,dummycol0=1;
       
       for(int i=0;i<colsize;i++)
       {
          for(int j=0;j<rowsize;j++)
          {
              if(matrix[i][j]==0)
              {
                  if(i==0 && j==0){dummyrow0=0;dummycol0=0;}
                  else if(j==0)dummycol0=0;
                  else if(i==0)dummyrow0=0;
                  else {matrix[0][j]=0;matrix[i][0]=0;}
              }
          }
       }
    
      for(int i=0;i<colsize;i++)
      {
          for(int j=0;j<rowsize;j++)
          {
             if(i==0 || j==0)continue;
             if(matrix[0][j]==0 || matrix[i][0]==0 )matrix[i][j]=0;
          }
      }
      
      if(dummyrow0==0)
      for(int row=0;row<rowsize;row++)matrix[0][row]=0;
      
      if(dummycol0==0)
      for(int col=0;col<colsize;col++)matrix[col][0]=0;
      
    }
};
