/*
Problem - Given a string, find a subsequence which is longest and is repeating in the string such that the two subsequences don’t have same string 
character at same position in the original string.

Understanding problem statement by example :                                   ------------------------(1)
Input string - "AABEBCDD"
Subsequence ABD is repeating in the string.

Indexes of A,B,D of first subsequence in the input string  : 0 2 7
Indexes of A,B,D of second subsequence in the input string  : 1 4 6

All indexes must be different.

Link - https://www.interviewbit.com/problems/repeating-subsequence/

I was not able to come up with the solution.Then i watched this - https://www.youtube.com/watch?v=oL7GCrcdaJI and it was clear to me!

Observation - 
1.We have to find a subsequence which is common at different indexes in the same string [Refer(1)].
2.Remember what LCS(s,s) says. It says that find a subsequence which is common in the same string.This further means that indexes can be same.
3.Difference between 1 and 2 is just the constraint of different indexes,rest all is same right?It means we have to find LCS with a restriction that indexes should be different

Solution - 
Find LCS between the two same input string, LCS(input string,input string) with a restriction that if both characters are same and if both characters are at 
different indexes, then count it in the common subsequence,otherwise not.

Similiarity:

Input   Problem   Output

a:       LCS       int/string
b:

a:       LRS       int/string
a: 

2 out of 3 are same.
Score : 2/3, hence LCS is the parent question of LRS.
*/

int dp[101][101];
int LCS(string &a,string &b,int n,int m)
{
    //base condition
    if(n==0 || m==0)return 0;
    
    //If its precalculated, then dont compute it again
    if(dp[n][m]!=-1)return dp[n][m];

    if(a[n-1]==b[m-1] && n!=m) //Restriction added.
    {
        return dp[n][m]=1+LCS(a,b,n-1,m-1);
    }
    else
    {
        return dp[n][m]=max(LCS(a,b,n,m-1),LCS(a,b,n-1,m));
    }
}
int Solution::anytwo(string A)
{
    int n=A.size();
    memset(dp,-1,sizeof(dp));
    if(LCS(A,A,n,n)>=2)return 1;
    else return 0 ;
}
