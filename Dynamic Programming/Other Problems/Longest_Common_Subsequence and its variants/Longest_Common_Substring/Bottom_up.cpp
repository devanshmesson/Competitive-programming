/*
Longest common substring
Two strings are given.Find out a substring which exists in both strings and its length is maximum over all possible common substrings.
Why DP is used to solve this problem?
-Because there is a need to check all the possibilities/subproblems in both strings and these subproblems may overlap.
DP checks all possibilities and picks up the optimal(minimum/maximum) one that is what we need in this problem.
Difference between longest common subsequence and longest common substring is that in the latter one, we have to find a string which is continuous in both strings.
In the Former one,non-continuous strings are acceptable.
Overlapping subproblems:
call : n,m-1 and n-1,m
call it again(else part comes):First call:n,m-2 and n-1,m-1 <-
                             :Second call:n-2,m and n-1,m-1 <-ALREADY COMPUTED ABOVE.SO DP IS REQUIRED.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s1,s2;
  cin>>s1>>s2;

  int n=s1.size(),m=s2.size();
  char s3[n+1],s4[m+1];

  for(int i=1;i<=n;i++)s3[i]=s1[i-1];
  for(int i=1;i<=m;i++)s4[i]=s2[i-1];

   vector<vector<int>>dp(n+1,vector<int>(m+1));
   
   //base case in recusrion=initilisation in bottom up

   //base case: if(n==0 || m==0)return 0;
   for(int i=0;i<=n;i++)dp[i][0]=0;
   for(int i=0;i<=m;i++)dp[0][i]=0;

  //code the choice diagram
    int result=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
         if(s3[i]==s4[j])
         {
           dp[i][j]=1+dp[i-1][j-1];
           result=max(result,dp[i][j]);
         }
         else 
         {
          result=max(result,max(dp[i-1][j],dp[i][j-1]));
         }
      }
    }

  cout<<result<<endl;
}
