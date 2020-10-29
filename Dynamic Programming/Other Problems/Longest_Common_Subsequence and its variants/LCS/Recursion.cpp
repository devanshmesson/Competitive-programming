/*
Longest common subsequence
Two strings are given.Find out a subsequence which exists in both strings and its length is maximum over all possible common subsequences.

Why DP is used to solve this problem?
-Because there is a need to check all the possibilities/subproblems in both strings and these subproblems may overlap.
DP checks all possibilities and picks up the optimal(minimum/maximum) one that is what we need in this problem.
*/
#include<bits/stdc++.h>
using namespace std;

int LCS(int n,int m,string s1,string s2)
{
  //base case
  if(n==-1 || m==-1)return 0;

  //choice diagram
  if(s1[n]==s2[m]) //when a character is common in both strings.Add it to the result.
  {
    return 1+LCS(n-1,m-1,s1,s2);
  }
  else  //When a character does not match
  {
    return max(LCS(n-1,m,s1,s2),LCS(n,m-1,s1,s2)); //Take maximum of the two choices to find out the length of longest subsequence.
  }
}

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int n=s1.size()-1,m=s2.size()-1;
  int length=LCS(n,m,s1,s2);
  cout<<length<<endl;
}
