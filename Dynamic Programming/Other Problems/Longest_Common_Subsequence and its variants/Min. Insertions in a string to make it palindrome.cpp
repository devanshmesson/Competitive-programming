/*
Problem  - Perform minimum of insertions in a string to make it a palindrome.
Link - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

Solution -  Compute the longest palindromic subsequence of the string. Basically our goal is to make the whole as the LPS.
So, the characters which are not the part of LPS, are present in the string odd times. So, we have to add all those characters which are not present in the LPS to make their occurence as even.
*/
int dp[501][501];
class Solution 
{
public:
    
    int LPS(string &s,int n, int m)
    {
        //base condition
        if(n==0 || m==0) return 0;
    
        if(dp[n][m]!=-1)return dp[n][m];
        
        //choice diagram
        if(s[n-1] == s[s.size()-m])return dp[n][m]=1+ LPS(s,n-1,m-1);
        else return dp[n][m]=max(LPS(s,n,m-1),LPS(s,n-1,m));
    }
    int minInsertions(string s) 
    {  
        for(int i=0;i<=s.size();i++)for(int j=0;j<=s.size();j++)dp[i][j]=-1;
        int LPS_size = LPS(s,s.size(),s.size());
        return s.size()-LPS_size;
    }
};
