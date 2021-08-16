/*
Problem Link - https://leetcode.com/problems/unique-paths/
Solution:1
Recursively generate all paths, at every step either we can go right or down.
Time complexity - O(2^(m*n))
Space complexity - O(1)

Solution:2
Memoize the recursive solution by making a 2d array.
OR
Do iteratively, by making the (m-1)th row and (n-1)th column as 1, because there is only 1 way to go to end cell of the matrix.
Rest other cells will be sum of right cell and down cell.
Time complexity - O((m*n))
Space complexity - O((m*n))

Solution:3
Observation:1 - Total number of directions to reach end cell = no_of_rows-1(downs) + no_of_columns-1(rights).
Observation:2 - Number of downs = no_of_rows-1 and  Number of rights = no_of_columns-1
We just have to choose Number of rights or Number of downs from Total number of directions, for which we will use combinations.

Example, m=2,n=3
Total number of directions to reach end cell = 3 (draw on paper)
Number of downs = 1 (m-1)
Number of rights = 2 (n-1)

Paths -
RRD 
DRR
RDR

We just have to choose 2 Rights or 1 down from 3 directions, for which we will use combinations (3C2).
3C2 = 3

So, formula will be - nCr
where-
n=no_of_rows-1(downs) + no_of_columns-1(rights).
r=minimum(no_of_rows-1,no_of_columns-1)

Time complexity - O(r * Log(n*r)) 
*/

//----------------------Code for solution 1-------------------------------------------

class Solution {
public:
    int ways(int m, int n,int fm,int fn)
    {
        if(m==fm-1 && n==fn-1)return 1;
        if(m>fm-1 || n>fn-1)return 0;
        return ways(m+1,n,fm,fn) + ways(m,n+1,fm,fn);
    }
    int uniquePaths(int m, int n) 
    {
      return ways(0,0,m,n);
    }
};

//----------------------Code for solution 2-------------------------------------------

class Solution {
public:
    int ways(int m, int n,int fm,int fn,vector<vector<int>>&dp)
    {
        if(m==fm-1 && n==fn-1)return 1;
        if(m>fm-1 || n>fn-1)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]=ways(m+1,n,fm,fn,dp) + ways(m,n+1,fm,fn,dp);
    }
    int uniquePaths(int m, int n) 
    {
      vector<vector<int>>dp(m,vector<int>(n,-1));
      for(int i=0;i<n;i++)dp[m-1][i]=1;
      for(int i=0;i<m;i++)dp[i][n-1]=1;
      return ways(0,0,m,n,dp);
    }
};

//----------------------Code for solution 3-------------------------------------------

class Solution {
public:
    
    int ncr(int n, int r)
    {
        int num=1,den=1;
        if(r>n-r)r=n-r;
        while(r!=0)
        {
            num*=n;
            den*=r;
            int gcd=__gcd(num,den);
            num/=gcd;
            den/=gcd;
            n--;
            r--;
        }
        return num/den;
    }
    int uniquePaths(int m, int n) 
    {
      int total_directions=m-1+n-1;
      return ncr(total_directions,min(m-1,n-1));
    }
};
