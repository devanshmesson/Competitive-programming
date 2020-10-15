/*
 Count No. of pair of subsets which have difference in sum = the given number
 n=5
 array->10 6 8 2 4
 difference=2

 Output=2 [(10 2 4),(6 8)]  [(10 6) (8 2 4)] 

 16-14=2
*/
#include<bits/stdc++.h>
using namespace std;

int subsetsum(int arr[],int target,int n,int **dp)
{
  //if already computed
  if(dp[n][target]!=-1)return dp[n][target];

  //base cases
  if(n==0 && target!=0)return 0;
  if(target==0){return 1;}

  //choice diagram
  
  if(arr[n]<=target) //Can include the item
  {
       return dp[n][target]=subsetsum(arr,target-arr[n],n-1,dp)+subsetsum(arr,target,n-1,dp); //include + not-include
  }
  else //arr[n]>target, cannot include
  {
    return dp[n][target]=subsetsum(arr,target,n-1,dp); // never include
  }

}
int main()
{
  int n,diff,sum=0;
  cin>>n;
  int arr[n+1];
  for(int i=1;i<=n;i++){cin>>arr[i];sum+=arr[i];}
  cin>>diff; //Count No. of pair of subsets which have difference in sum = "diff"
  int s1,s2;//let s1 be sum of first subset , s2 be sum of second subset

  /*
  s1+s2=sum , Sum of both subsets will be sum of whole array as we are partitioning the array into 2 subsets.
  s1-s2=diff
  s1=sum-s2

  sum-s2-s2=diff
  sum-2*s2=diff
  sum-diff=2*s2

  (sum-diff)/2=s2 -(1)

  From (1)
  Problem boils down to finding out number of subsets having sum=s2.
  So apply subset sum problem with:
  size of array=n 
  target=s2
  */
  
  s2=(sum-diff)/2;
  int target=min(s2,sum-s2); //finding shorter sum will save time and memory!
  /*For Memoization declare dp*/

  int** dp=new int*[n+1];//dynamically assigning rows to dp
  for(int row=0;row<=n;row++)dp[row]=new int[target+1];//dynamically assigning columns to rows in dp

  for(int i=0;i<=n;i++)for(int j=0;j<=target;j++)dp[i][j]=-1;
  int answer=subsetsum(arr,target,n,dp);
  cout<<answer<<endl; // No. of pair of subsets which have difference in sum = "diff"
  return 0;
}
