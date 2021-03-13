/*
Problem -  Given two strings, calculate the minimum no. of insertions and deletions to convert string a to b
Link - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Observtions - 
1.Uncommon characters will be deleted for sure.
2.Common characters which are not in order will be deleted for sure.

example - 
s = "heap" t="pea"

Uncommon characters - h
Common characters not in order - p

what's left?
The common characters which are in order. that is : e and a

Minimum no. of deletions/insertions means not deleting/inserting maximum characters  ------(1)

Which characters are not deleted/inserted ? Answer : The characters which are common and are in order.

So, we have to maximize the characters which are common and are in order.
Characters which are common and are in order is also known as a "common subsequence"
Maximizing common subsequence is also known as the "longest common subsequence".

From(1), Minimum no. of deletions/insertions means not deleting/insertimg longest common subsequence.
This means Longest common subsequence will be saved.

Which eventually means that Following characters will be deleted/added :   ------(2)
1.Uncommon characters.
2.Common characters which are not in order.

Operation of deletion : 
Let s be the length of string s and t be the length of string t. 
Let x be the length of LCS.

No. of Characters which will be deleted from string s to form LCS: s-x  (Refer (2))
No. of Characters which will be added to LCS to form string t: t-x      (Refer (2))

Total - s-x + t-x


--------------------- OR -------------------------------
It can be understood in another way too :

Let s be the length of string s and t be the length of string t. 
Let x be the length of LCS.

No. of Characters which will be deleted from string s: s-x  (Refer (2))
No. of Characters which will be added to s: t-x      (Refer (2))

Total - s-x + t-x
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	int dp[1002][1002];
	int len=0;
	int lcs(int n,int m,string &str1,string &str2)  //calculating length of LCS
	{
	   
	  //base condition
	  if(n==0 || m==0)return 0;
	  
	  //if the comparison has already been made before then return it
	  if(dp[n][m]!=-1) return dp[n][m];
	  
	  //choice diagram
	  if(str1[n]==str2[m])
	  {
	     return dp[n][m]=1+lcs(n-1,m-1,str1,str2);
	  }
	  else
	  {
	     return dp[n][m]=max(lcs(n,m-1,str1,str2), lcs(n-1,m,str1,str2));
	  }
	  
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.size(),m=str2.size();
	    
	    for(int i=n-1;i>=0;i--)str1[i+1]=str1[i]; //convert to 1 based indexing
	    for(int i=m-1;i>=0;i--)str2[i+1]=str2[i]; //convert to 1 based indexing
	    
	    len=0;
	    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[i][j]=-1;
	    lcs(n,m,str1,str2);  //Calculating length of longest common subsequence
	    int i=n,j=m,sz=0;
	    string common;
	    while(i>0 && j>0)   //This loop fetches longest common subsequence string
	    {
	        if(str1[i]==str2[j])
	        {
	            common.push_back(str1[i]);
	            i--;
	            j--;
	        }
	        else 
	        {
	            if(dp[i][j-1] > dp[i-1][j])j--;
	            else i--;
	        }
	    }
	    reverse(common.begin(),common.end());   //as the previous loop fetches the string in reverse order so it make it straight we reverse it again.
	    i=common.size();
	    return (n-i) + (m-i);  // (n-i) are the deletions and (m-i) are the insertions
	} 
};

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
	      Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
    }
    return 0;
}
