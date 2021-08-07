/*
Problem link - https://leetcode.com/problems/pascals-triangle/

Note: To find element at particular row and column in pascal triangle, formula = row C column (row combination column). [Considering 0 based indexing]
Time complexity of nCr = O(min(r,n-r)) = O(min(column,row-column)) = O(Column/2) = O(column) = O(row) [row=column in pascal triangle]

Solution 1:
For every row, find all elements using the formula of nCr.
Calculating time complexity,
for each row, O(row)
for each column in that particular row, O(column) = O(row)
Calculate nCr for each column in that particular row = O(row)

So, Time complexity = O(row^3)

Solution 2:(optimized)
Observation:
pascal_triangle[i][j] = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j] --------(1)

For every row, find all elements using the formula (1).
Calculating time complexity,
for each row, O(row)
for each column in that particular row, O(column) = O(row)
Calculate element value for each column in that particular row = O(1)

So, Time complexity = O(row^2)

----------------------------------------------------------------------------VARIANTS OF THIS Problem---------------------------------------------------------------------
Variant:1
To find a particular element in tha pascal triangle, say element at ith row and jth column:
Solution:1 Calulate all elements of every row, till we reach the row at which the element value is supposed to be found(Same as the current problem).
Time complexity - O(row^2)

Solution:2 Use the formula of nCr. Time complexity - O(row)
for example to calculate element value at 5th row 4th column(0 based indexing), just apply 5C4.
------------------------------------------------------------------------------------------------------------------------------------------------------------------
Variant:2 (Problem Link - https://leetcode.com/problems/pascals-triangle-ii/submissions/)
To find a particular row of pascal triangle, say ith row.
Solution 1: Calulate all elements of every row,till we reach the row which is suppossed to be calculated. Time complexity - O(row^2)
Solution 2: Calculate only ith row, by traversing all elements and calculating the value by the nCr formula. Time complexity - O(row^2).

Code for solution 2 - 
class Solution {
public:
    int ncr(int n,int r)
    {
        if(r==0 || r==n)return 1;
        int res=1,stop,num=1,den=1;
        r=min(r,n-r);
        stop=r;
        
        while(r!=0)
        { 
        int div=__gcd(num,den);
        num/=div;
        den/=div;
        num*=n;
        den*=r;
        n--;
        r--;
        }
        res=num/den;
        return res;
    }
    vector<int> getRow(int rowIndex) 
    {
        vector<int>ans;
        for(int i=0;i<=rowIndex;i++)
        {
         ans.push_back(ncr(rowIndex,i)); 
        }
        return ans;
    }
};
*/

vector<vector<int>> generate(int numRows) 
    {
      vector<vector<int>>ans(numRows);
    
      ans[0].resize(1);
      ans[0][0]=1;
      for(int i=1;i<numRows;i++)
      {
         ans[i].resize(i+1);
         ans[i][0]=ans[i][i]=1;
        for(int j=1;j<i;j++)
        {   
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
      }
        return ans;
    }
};
