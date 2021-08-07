/*
Problem Link - https://leetcode.com/problems/set-matrix-zeroes/

Solution 1:
Perform Bruteforce by traversing every element of the matrix, and if the element is 0, then traverse it's coressponding row and column.
Time complexity - O((N*M) * (N+M))
Space Complexity - O(1)

Solution 2:
Make two hash arrays, one for row and another for column.
Traverse every element of the matrix and if the element is 0, suppose if element is in ith row and jth column, then hashrow[i]=0 and hashrow[j]=0,
0 denotes, to convert all elements of that whole row/column to 0.

Traverse the matrix again, if ith row(or jth column) is marked as 1, make every element of that row/column as 0.

Time complexity - O(2*(N*M))
Space Complexity - O(N+M)

Solution 3:
Make first row of the matrix as hashrow and make first column of the matrix as hashcolumn to reduce space.

Traverse every element of the matrix and if the element is 0, suppose if element is in ith row and jth column, then matrix[0][j]=0 and matrix[i][0]=0,
0 denotes, to convert all elements of that whole row/column to 0.

Traverse every element of the matrix and if a element at 1st row, jth column is 0, then convert all elements of jth column to 0.
Traverse every element of the matrix and if a element at ith row, 0th column is 0, then convert all elements of ith row to 0.

Matric[0][0] can denote row as well as column, thats why "dummyrow0" and "dummycol0" is made to avoid confusion.
if dummyrow0 == 0, it means that we have to convert all elements of 0th row to 0.
if dummyrcol0 == 0, it means that we have to convert all elements of 0th column to 0.

Time complexity = O(2* [(N*M) + (N+M)])
Space Complexity = O(1)

*/
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
