/*Count no. of subsets which has sum equal to the given sum 
 n=4
 array->2 3 4 5
 target sum=7
 answer=2 [5 2] [3 4] these two subets sum to 7.
*/

#include<bits/stdc++.h>
using namespace std;
int ans=0;

int countsubsets(int weight[],int target,int n,int **dp)
{
  //base case
  if(n==0 && target!=0)return 0;
  if(target==0)return 1;

  //if already computed no need to calculate again
  if(dp[target][n]!=-1)return dp[target][n];

  //choice diagram
  if(weight[n]<=target) //can include the item
  {
    return ans=dp[target][n]=countsubsets(weight,target-weight[n],n-1,dp)+countsubsets(weight,target,n-1,dp); //add the subsets found when we included that item and not include that item
  }
  else //cannot include the item
  {
    return ans=dp[target][n]=countsubsets(weight,target,n-1,dp); //never include that item
  }
}
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
  for(int row=1;row<=target;row++)dp[row]=new int[n+1]; //dynamically allocate columns in every row
  for(int i=1;i<=target;i++)for(int j=1;j<=n;j++)dp[i][j]=-1;
  countsubsets(weight,target,n,dp);
  cout<<ans<<endl;
  return 0;
}
