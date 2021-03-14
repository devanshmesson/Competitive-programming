/*
Problem - Given a string s, find a subsequence which is longest as well as a palindrome.
Link - https://leetcode.com/problems/longest-palindromic-subsequence/

A palindrome means that if we read a string from front, it will be exactly same when it is being read from it's back.

In other words, we can say that, we have to find longest subsequence which is common between a string and it's reverse.

So, take another string 't' which is reverse of string 's'.Find the longest common subsequence between string s and string t;

|------------------------------------|
|    LPS(s) = LCS (s,reverse(s))     |
|------------------------------------|

INPUT      PROBLEM   OUTPUT
a:        LCS       INT
b:
--------------------------
a:        LPS       INT
rev(a):

Match    not        match
-ing    matching    -ing

Score 2/3 [2 out of 3 things are matching so LCS is a parent question of LCS]
*/
class Solution 
{
public:

    int longestPalindromeSubseq(string s)
    {
        int n=s.size();
        string a(n+1,' '),b(n+1,' ');
        for(int i=0;i<n;i++)
        {
            a[i+1]=s[i];
            b[n-i]=s[i];
        }
        int dp[n+1][n+1];
        memset(dp,-1,sizeof(dp));        
    
        
        //base case: a is null || b is null
        for(int i=0;i<=n;i++){dp[0][i]=0; dp[i][0]=0;}
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j] , dp[i][j-1]); 
            }
        }
        return dp[n][n];
    }
};
