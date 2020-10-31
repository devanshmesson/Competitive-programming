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

int main()
{
  string s1,s2,s3,s4;
  cin>>s1>>s2;
  int n=s1.size(),m=s2.size();
  for(int i=1;i<=n;i++)s3[i]=s1[i-1];
  for(int i=1;i<=m;i++)s4[i]=s2[i-1];
  
  vector<vector<int>>dp(n+1,vector<int>(m+1));
  vector<vector<bool>>path(n+1,vector<bool>(m+1)); //boolean matrix storing which characters are in the path sequence-wise.

  //base case in recusrion = initialisation in bottom up DP

  //base case: if(n==0 || m==0)return 0
  for(int i=0;i<=m;i++)dp[0][i]=0;
  for(int j=0;j<=n;j++)dp[j][0]=0;

  //Code the choice diagram
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s3[i]==s4[j])
      {
        path[i][j]=1;  //1 is signifying that this character is included in LCS.
        dp[i][j]=1+dp[i-1][j-1]; 
      }
      else 
      {  
        path[i][j]=0;  //0 is signifying that this character is not included in LCS but it will give the way to the next character by
                       //taking out the maximum of  dp[i][j-1] & dp[i-1][j] and process continues like this.
        dp[i][j]=max( dp[i][j-1] , dp[i-1][j] );                       
      }
    }
  }
  //Printing longest common subsequence string and its length
  int i=n,j=m;
  vector<int>paths1,paths2;

  while(1)
  {
     if(i==0 || j==0)break; 
     if(path[i][j]==1) //include the character in the LCS
      {
        paths1.push_back(i);
        paths2.push_back(j);
        i--;j--;
      }
      else if(path[i][j]==0)
      {
        if(dp[i][j-1] >= dp[i-1][j]) //not-include the character in the LCS.take out the maximum of  dp[i][j-1] & dp[i-1][j] and check then check if it can be 
                                     //included in LCS or not.if not,then continue this process again.if yes,then inlclude the character in LCS.
        {
          j--;
        }
        else
        {
          i--;
        }
      }
  }
  reverse(paths1.begin(),paths1.end()); //reversing is done because we have to print the string from left to right.
  reverse(paths2.begin(),paths2.end());

  cout<<"Indexes at which LCS is present in 1st string"<<endl;
  for(auto x:paths1)cout<<x<<" ";
  cout<<"\nIndexes at which LCS is present in 2nd string"<<endl;
  for(auto x:paths2)cout<<x<<" ";
  cout<<"\nLength of the longest common subsequence is:"<<dp[n][m]<<endl;
}
