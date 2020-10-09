/*Count no. of subsets which has sum equal to the given sum 
 n=4
 array->2 3 4 5
 target sum=7
 answer=2 [5 2] [3 4] these two subets sum to 7.
*/
#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main()
{
  int n,target;
  cin>>n;
  int weight[n+1];
  for(int i=1;i<=n;i++)cin>>weight[i];
  cin>>target;
 
  /*Note : In Yes/No answer will be in form of 1/0 , To count no. of subsets
    answer will be in form of numbers*/

  /*In recursion,final answer is stored in the variable which was used to start
   the recursion according to stack.*/
  
  int **dp;
  dp=new int*[target+1]; //dynamically allocate row pointers
  for(int row=0;row<=target;row++)dp[row]=new int[n+1]; //dynamically allocate columns in every row

  //Base case in recursion = initialization in bottom-up DP

  //base-case 1 target=0 then return 1
  for(int i=0;i<=n;i++)dp[0][i]=1;

  //base-case 2 target!=0 and n==0 then return 0
  for(int i=1;i<=target;i++)dp[i][0]=0;

  //Choice diagram
  for(int i=1;i<=target;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(weight[j]<=i) //can include the item
      {
        dp[i][j]=dp[i-weight[j]][j-1] + dp[i][j-1];
      }
      else //cannot include the item
      {
        dp[i][j]=dp[i][j-1];
      }
    }
  }
  cout<<dp[target][n]<<endl;
  return 0;
}
