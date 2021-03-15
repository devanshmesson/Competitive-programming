/*
Problem - Calculate minimum number of deletions in a string to make it a palindrome.
Characters can be deleted from anywhere in the string.
Link - https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1#

Expected Time Complexity: O(|S|^2)
Expected Auxiliary Space: O(|S|^2)

Observation -
1.If the string is itself a palindrome, then answer = 0.

2. Characters can be deleted from anywhere in the string, it means that palindrome can be present in the string as a subsequence.Removing the characters 
in between the subsequence will make the string palindrome.

3. Minimum deletions is inversly proportional to length of palindromic subsequence. So, maximize the length of palindromic subsequence to get minimum deletions.

4. You got your answer, Just calculate length of longest palindromic subsequence.

5. Number of deletions :  Length of input string   -  length of longest palindromic subsequence.

Note (Very important)  : when i called the function by value, meaning when i passed string s and string t in function, I GOT TLE.
                       : when i called the function by reference, meaning when i passed string &s and string &t in function, I GOT AC.
                       :This is because in call by value, string are being copied which takes time and in reference string are not copied in function(its the same string)

*/
int dp[1001][1001];
int LCS(string &s,string &t,int n,int m)
{
  //base condition
  if(n==0 || m==0)return 0;
  
  //If its already stored, then dont compute it again.
  if(dp[n][m]!=-1)return dp[n][m];
  
  //choice diagram
  if(s[n]==t[m])return dp[n][m]=1+LCS(s,t,n-1,m-1);
  else return dp[n][m]=max(LCS(s,t,n,m-1),LCS(s,t,n-1,m));
  
}
int minimumNumberOfDeletions(string S) 
{ 
   int sz=S.size();
   string rev(sz+1,' ');
   S.resize(sz+1);
   for(int i=sz-1;i>=0;i--)
   {
      S[i+1]=S[i];
      rev[sz-i]=S[i];
   }
   for(int i=0;i<=sz;i++)for(int j=0;j<=sz;j++)dp[i][j]=-1;
   for(int i=0;i<=sz;i++){dp[i][0]=0;dp[0][i]=0;}
   int restore_length=LCS(S,rev,sz,sz);
   return sz-restore_length;
} 
