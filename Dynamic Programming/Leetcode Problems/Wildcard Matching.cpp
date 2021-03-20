/*

Problem - Given two strings - namely, s and p.

s contains only a-z
p contains (a-z), '?' , '*'

'?' can replace any single character from (a-z)
'*' can replace a null character or a string containing (a-z).

Task - Return 1, if it's possible to convert p to s, otherwise return NO.

Why it is a DP problem   ? 
Ans - In some test cases, subproblems occur.

I did'nt understood the Top-dow DP solution for this problem.
But i understood the bottom up Dp solution for this problem (https://youtu.be/NbgUZAoIz3g)


Explanation - 

Let's take an example to understand it.

s- babaaab   (j)
p- ?a**ab    (i)

Start iterating both strings from starting.

1. i=0, j=0 :   p[0]='?' , this can be equated to b, by putting '?' as 'b'.
2. i=1, j=1 :   p[1]=s[1]
3. i=3, j=3 :   * can replace a string or a null character.
            :   If * replaces a null character, then our problem reduces to:  s=ba, p=?a . a!=b so return 0.
            :   If * replaces 'b',  then our problem reduces to:  s=bab, p=?ab .so, return 1.
            :   If * replaces "ab", then our problem reduces to:  s=b, p=?a .so, return 0.
            :   If * replaces "bab", then our problem reduces to:  s=' ', p=?a .so, return 0.'

If in worst case '*' lies in the end of p, then comparisons will n times. which can be O(n^3) solution. [O(n^2) for DP * O(n) = OP(n^3)]
Here we can optimize our solution, there is no need to perform n comparisons, we can consider two cases,

Case 1: If * replaces a blank. dp[i-1][j] in the matrix
Case 2: If * replaces a string. dp[i-1][j-1], dp[i-1][j-2], dp[i-1][j-3],....., dp[i-1][0]. [This has to be optimized.]

Answer is CASE:1 OR CASE:2

Please draw the matrix to easily understand.
Optimization :

Q1 - What is the answer for dp[5][0], where p[5]='*',
Answer is dp[4][0],                                     dp[5][0]=dp[4][0]

Q2 - What is the answer for dp[5][1], where p[5]='*',
Answer is dp[4][1] (* replaces blank) OR dp[4][0] (* replaces the jth (1st) character)

As, dp[5][0]=dp[4][0].
can we write it as,  Answer is dp[4][1] OR dp[5][0].    dp[5][1] = dp[4][0] || dp[4][1]

Q3 - What is the answer for dp[5][2], where p[5]='*',
Answer is dp[4][2] OR dp[4][1]  OR dp[4][0].

As  dp[5][1] = dp[4][0] || dp[4][1]
can we write it as,  Answer is dp[4][2] OR dp[5][1].

Conclusion, instead of traversing the whole i-1th row, just bitwise OR two values, dp[i-1][j] OR dp[i][j-1]. That's it.



Solution - 

if p[i] is '?', equate it with s[j], if dp[i-1][j-1] is 1 then dp[i][j]=1
if p[i] is '*' , dp[i][j] = dp[i-1][j] OR dp[i][j-1]
if p[i] is (a-z), and if s[j]==p[i], if dp[i-1][j-1] is 1 then dp[i][j]=1

*/

class Solution 
{
    public:
   
    bool isMatch(string s, string p) 
    {
        int n=s.size();
        int m=p.size();
        
         int dp[n+1][m+1];
        //base condition
        
        //case 1: n==0 m==0
        dp[0][0]=1;
        
        //case 2: m==0 and n!=0
        for(int i=1;i<=n;i++)dp[i][0]=0;
        
        //case 3: m!=0 and n==0
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*') dp[0][i] = dp[0][i-1];
            else dp[0][i]=0;
        }
        
        
        //choice diagram
        for(int i=1;i<=n;i++)
        {
          for(int j=1;j<=m;j++)
          {
              if(s[i-1]==p[j-1] || p[j-1]=='?')dp[i][j]=dp[i-1][j-1];
              else if(p[j-1]=='*')dp[i][j]=dp[i-1][j] || dp[i][j-1];
              else dp[i][j]=0;
          }
        }
        return dp[n][m];
    }
};
