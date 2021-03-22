/*
Problem - N number of matrices are given, Task is to multiply all the matrices by performing minimum number of multplications.
Link- https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#

Expected Time Complexity: O(N^3)
Expected Auxiliary Space: O(N^2)

Number of multiplications depends on the order in which you multiply the matrices.
For example,

Matrices -> A1, A2, A3, A4

Reference:
Order:1 to multiply : (A1)*(A2*A3*A4)
Order:2 to multiply : (A1*A2)*(A3*A4)
Order:3 to multiply : (A1*A2*A3)*(A4)

These different orders of multiplications result into different number of multiplications.
So DP is used to solve this problem because it will solve all possibilities and choose the optimal one.It also saves time by memoizing the overlapping subproblems.

Solution - 
1.Partition the matrices at every prefix or matrix one by one. (Prefix is wriiten for understanding)
2.Like in order:1, we partitioned the matrices at the first prefix OR the first matrix.
3.After partition at a certain prefix, it will get divided into two groups of matrices, left and right.
4.Calculate the cost of multiplying left group of matrices recursively (C1).Similarly, Calculate the cost of multiplying right group of matrices recursively.(C2)
5.Calculate the cost of multiplying the resultant matrix of left and resultant matrix of right.(C3)
6.Add C1,C2,C3. This is the total cost of multiplying all matrices.

Try these steps for every order of multiplication (see reference) and choose the minimum cost as the final optimal cost.

Top-down (Memoization) is much easier than  Bottom up DP.That's why i learnt only memoization.
*/

int dp[101][101];
class Solution
{
    public:
    int MCM(int *arr, int i, int j)
    {
       //base condition
       if(i>=j)return 0;
       
       if(dp[i][j]!=-1)return dp[i][j];
       
       int mincost=INT_MAX;
     
       for(int k=i;k<j;k++)
       {
          int left=MCM(arr,i,k); //cost of subproblem
          int right=MCM(arr,k+1,j);  //cost of subproblem
          int cost_of_multiplication=arr[i-1]*arr[k]*arr[j]; //cost of multiplying left and right matrix
          mincost=min(mincost,cost_of_multiplication + left + right);
       }
       return dp[i][j]=mincost;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
       //Step 1 : select i and j 
       //Step 2 : Think the base condition (think of the first invalid input)
       //Step 3 : Write the loop
       //Step 4 : Calculate C1+C2+C3 and take the minimum one as the answer.
       memset(dp,-1,sizeof(dp));
       MCM(arr,1,N-1);
       
    }
};
