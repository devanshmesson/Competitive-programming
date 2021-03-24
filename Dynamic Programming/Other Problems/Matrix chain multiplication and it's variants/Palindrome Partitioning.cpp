/*
Problem  - Given a string, divide this string in such a way that every substring is a palindrome.Number of divisions must be minimum.
Link - https://www.interviewbit.com/problems/palindrome-partitioning-ii/

This problem can be related to matrix chain multiplication because we have to perform partitions in the string.In matrix chain multiplication, partition 
in the matrices was performed and the partition which gave the minimum cost was chosen.

For example,
string -> "nitik"


Minimum partition - n | iti | k 
Every substring is a palindrome.

So DP is used to solve this problem because it will solve all possibilities and choose the optimal one.It also saves time by memoizing the overlapping subproblems.

Solution - 
1.First of all, why we are doing partition? Ans- because the whole string is not palindrome.For ex - "nitin" will not be partitioned further beacuse it's already
a palindrome and minimum no. of partitions must be performed.

2.Check whether the current string is a palindrome or not.If its a palindrome, return 0. Otherwise, proceed.
3.Partition the string at every prefix or character one by one. (Prefix is written for understanding)
4..After partition at a certain prefix, it will get divided into two groups of matrices, left and right.
5.Calculate Cost of partitioning left group of characters recursively (C1).Similarly,Calculate Cost of partitioning right group of characters recursively.(C2)
5.The cost of partitioning the string (at point 2) will always be 1. Because we are counting a partition as 1.
6.Add C1,C2,C3. This is the total cost of partitioning the string.
Try these steps for every order of partition  and choose the minimum cost as the final optimal cost.

This code gave TLE at GFG.But exactly same code gave AC on Interviewbit.I didn't submit on leetcode as printing MCM is pending.
Top-down (Memoization) is much easier than  Bottom up DP.That's why i learnt only memoization.

*/
class Solution
{
public:
    int palindrome_check(string &s,int i,int j)
    {
      while(i<j){ if(s[i]!=s[j])return 0; i++; j--;}
      return 1;
    }
    int MCM(string &s,int i,int j,int **dp)
    {
      //Step:2 Think of the base condition(invalid input)
      if(i>=j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      if(palindrome_check(s,i,j)==1)return dp[i][j]=0;
      
      //Step:3 Iterate k from i to j
      int total=INT_MAX;
      for(int k=i;k<j;k++)
      {
         int left=MCM(s,i,k,dp);
         int right=MCM(s,k+1,j,dp);
         total=min(total,left+right+1);
         if(total==1)return 1;
      }
      return dp[i][j]=total;
    }
    int palindromicPartition(string str)
    {
        int n=str.size();
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)dp[i]=new int[n+1];
       for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;
        //step:1 determine i and j 
        MCM(str,0,str.size()-1,dp);
    }
};
