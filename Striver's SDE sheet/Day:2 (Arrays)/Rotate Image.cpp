/*
Problem Link - https://leetcode.com/problems/rotate-image/
Solution:1
Initialize a matrix and copy ith column of input matrix to the ith row of new matrix.
Time complexity - O(n^2)
Space complexity - O(n^2)

Solution:2
Observation here is that, the desired output is the transpose of the input matrix with it's rows being reversed.
Time complexity - O(n^2)
Space complexity - O(1)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        //Transpose the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Reverse all rows
        int half=n/2;
        for(int i=0;i<n;i++)
        {
         for(int j=0;j<half;j++)swap(matrix[i][j],matrix[i][n-j-1]);
        }
    }
};
