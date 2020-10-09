/*Count no. of subsets which has sum equal to the given sum 
 n=4
 array->2 3 4 5
 target sum=7
 answer=2 [5 2] [3 4] these two subets sum to 7.
*/

#include<bits/stdc++.h>
using namespace std;
int ans=0;
int countsubsets(int weight[],int target,int n)
{
  //base case
  if(n==0 && target!=0)return 0;
  if(target==0)return 1;

  //choice diagram
  if(weight[n]<=target) //can include the item
  {
    return ans=countsubsets(weight,target-weight[n],n-1)+countsubsets(weight,target,n-1); //add the subsets found when we included that item and not included that item
  }
  else //cannot include the item
  {
    return ans=countsubsets(weight,target,n-1); //never include that item
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
  
  countsubsets(weight,target,n);
  cout<<ans<<endl;
  return 0;
}
