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

int LC_substring(int n,int m,char s1[],char s2[],int longest)
{
  //base case
  if(n==0 || m==0)return longest;

  //code the choice diagram
  if(s1[n]==s2[m])
  {
   return longest=max(longest,LC_substring(n-1,m-1,s1,s2,1+longest)); //add one if character is equal in both strings.
  }
  else
  {
    return longest=max(longest, max( LC_substring(n,m-1,s1,s2,0) , LC_substring(n-1,m,s1,s2,0))); //when character dont match then we start the counter from 0.
                                                                                                 //we dont add it in the result.we make a new result and pick up
                                                                                                 //the maximum value.
  }

}

int main()
{
  string s1,s2;
  cin>>s1>>s2;

  int n=s1.size(),m=s2.size();
  char s3[n+1],s4[m+1];

  for(int i=1;i<=n;i++)s3[i]=s1[i-1]; //Covert it to 1 based indexing for convinience.
  for(int i=1;i<=m;i++)s4[i]=s2[i-1];

  int length=LC_substring(n,m,s3,s4,0);
  cout<<length<<endl;
}
