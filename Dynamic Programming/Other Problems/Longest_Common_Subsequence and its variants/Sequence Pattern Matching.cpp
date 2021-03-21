/*
Problem - Given a string p and string s. Find out whether p is present in as a subsequence.
Link - https://www.youtube.com/watch?v=QVntmksK2es&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=31

Observation - 

Maximum length of Longest common subsequence between two strings a and b = min(a.size() , b.size())
p should be present in s as a subsequence.This can also be said as LCS between p and s should be p.
So just calculate LCS(s,p). If length of LCS  = length of p.Then p is present in s as a subsequence.
Otherwise it's not present.
*/

#include<bits/stdc++.h>
using namespace std;
 
 int nn,mm;

 int dp[2001][2001];
 int LCS(string &s, string &p, int n ,int m)
 {
    //base case
    if(n==0 || m==0)return 0;
    
    if(dp[n][m]!=-1)return dp[n][m];

    //choice diagram
    if(s[n-1]==p[m-1])
    {
      return dp[n][m]=1+LCS(s,p,n-1,m-1);
    }
    else 
    {
      return dp[n][m]=max(LCS(s,p,n,m-1),LCS(s,p,n-1,m));
    }

 }

int main()
{
  string s,p;
  cin>>s>>p;

  nn=s.size();
  mm=p.size();

  for(int i=0;i<=nn;i++)for(int j=0;j<=mm;j++)dp[i][j]=-1;
  int ans=LCS(s,p,s.size(),p.size());
  
  if(ans==p.size())cout<<"YES, p is present in s as a sequence"<<endl;
  else cout<<"NO, p is not present in s as a sequence"<<endl;


}
