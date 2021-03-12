/*
Probem- Given two strings (s and t), find the shortest common supersequence of those two strings.
Link- https://leetcode.com/problems/shortest-common-supersequence/
A supersequence is string which contains s and t both as a subsequence.

Solution - 
For example, 
s="abac"
t="cab"

Longest common supersequence will be : s+t -> abaccab

We can minimize the longest common supersequence by removing the common letters in the both the strings.
So,Find the longest common subsequence of both strings.
Remove the longest common subsequence from Longest common supersequence and result will be shortest common supersequence.

Longest common supersequence - Longest common subsequence = Shortest common supersequence
Find LCS using dp.

Shorest common supersequence will be generated as follows:

Print the string s and string t until a character of LCS is encountered in both strings, If a common character appears in both string,
print that common character and continue the same process for the next character of LCS.
  
This way order will be maintained and both strings will bw present as subsequences in SCS.

Time complexity - O(size(s) * size(t)) -  Majorly calculating LCS contributes to time complexity.
*/
class Solution 
{
public:
    int dp[1001][1001];    // Using 2d vector inplace of 2d array increase time and memory (check leetcode submissions).
    string shortestCommonSupersequence(string str1, string str2) 
    {
       int n=str1.size();
       int m=str2.size();
           
       for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j]=-1;
        
       //base case
       //case:1 n==0 return 0
       for(int i=0;i<=m;i++)dp[0][i]=0;
        
       //case:2 m==0, then return 0
       for(int i=0;i<=n;i++)dp[i][0]=0;
        
        //choice diagram - Calculating the Length of longest common subsequence
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
        //Fetching the Longest common subsequence
        string lcstring;
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                lcstring.push_back(str1[i-1]);
                i--; j--;
            }
            else
            {
                if(dp[i-1][j]  > dp[i][j-1])i--;
                else j--;
            }
        }
        
        
        reverse(lcstring.begin(),lcstring.end()); //Longest common subsequnce was filled in reverse, in order to keep it straight, reverse it again.
      
        //generating supersequence 
        int ps=0,pt=0,sz=lcstring.size();
        
        string scs;
        for(int i=0;i<sz;i++)   //Iterating over the longest common subsequence
        {
            char ch=lcstring[i];
            
            for(int j=ps;j<n;j++)   //Printing s until a common character appears
            {
                if(str1[j]==ch){ps=j+1;break;}
                scs.push_back(str1[j]);
            }

            for(int j=pt;j<m;j++)  //Printing t until a common character appears
            {
                if(str2[j]==ch){pt=j+1;break;}
                scs.push_back(str2[j]);
            }
            scs.push_back(ch);    //Printing the common character. This way we minimize the length of supersequence because we add the common characters only once.
        }
        
        while(ps<n){scs.push_back(str1[ps]);ps++;}  //if some letters are left after there are no more common characters, then print it.
        while(pt<m){scs.push_back(str2[pt]);pt++;} //if some letters are left after there are no more common characters, then print it.
        
        
        return scs;  //Return the shorest common supersequence. 
       
    }
};
