/*
Longest common subsequence
Two strings are given.Find out a subsequence which exists in both strings and its length is maximum over all possible common subsequences.
Why DP is used to solve this problem?
-Because there is a need to check all the possibilities/subproblems in both strings and these subproblems may overlap.
DP checks all possibilities and picks up the optimal(minimum/maximum) one that is what we need in this problem.

Overlapping subproblems:
call : n,m-1 and n-1,m
call it again(else part comes):First call:n,m-2 and n-1,m-1 <-
                             :Second call:n-2,m and n-1,m-1 <-ALREADY COMPUTED ABOVE.SO DP IS REQUIRED.
                             

*/


#include<bits/stdc++.h>
using namespace std;

int LCS(int n,int m,string s1,string s2,vector<vector<int>>&dp)
{
  
  //base case
  if(n==-1 || m==-1){return 0;}

  //if already computed
  if(dp[n][m]!=-1){return dp[n][m];}

  //choice diagram
  if(s1[n]==s2[m])
  {
    return dp[n][m]=1+LCS(n-1,m-1,s1,s2,dp);
  }
  else 
  {
    return dp[n][m]=max(LCS(n-1,m,s1,s2,dp),LCS(n,m-1,s1,s2,dp));
  }
}

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int n=s1.size()-1,m=s2.size()-1;
  vector<vector<int>>dp(n+1,vector<int>(m+1));

  for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j]=-1;

  int length=LCS(n,m,s1,s2,dp);
  cout<<length<<endl;

}
