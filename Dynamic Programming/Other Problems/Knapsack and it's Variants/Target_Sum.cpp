/*
 No. of ways to get sum=the given number if negative or positive sign can be  given to 
 every number in the array.
 n=3
 array->1 2 3 
 target sum=2

 Output=1 [1-2+3]

1-2+3=1 , count in how many ways we can to target sum
*/
#include<bits/stdc++.h>
using namespace std;

int targetsum(int arr[],int target,int n,int** dp)
{
  //if already calculated 
  if(dp[target][n]!=-1)return dp[target][n];
 
  //base case
  if(target==0)return 1;
  if(n==0 && target!=0)return 0;
  
  //choice diagram
  if(arr[n]<=target) //can include the item
  {
    return dp[target][n]=targetsum(arr,target-arr[n],n-1,dp) + targetsum(arr,target,n-1,dp); //include + not-include
  }
  else
  {
    return dp[target][n]=targetsum(arr,target,n-1,dp);
  }
 
}
int main()
{
  int n,target,sum=0;
  cin>>n;
  int arr[n+1];
  for(int i=1;i<=n;i++){cin>>arr[i];sum+=arr[i];}
  cin>>target;
  /*
   Segregate the array into two type of numbers :positive and negative
   [positive numbers array] + [negative numbers array]=target sum
   [positive numbers array] - abs([negative numbers array])=target sum
   [subsetsum 1]-[subsetsum 2]=target sum

   So,Problem boils down to Calculating no. of pair of subsets which has 
   difference in sum = target sum

   let s1,s2; subsetsu of both subsets

   s1+s2=total_array_sum
   s1-s2=target sum

   total_array_sum-s2-s2=target sum
   total_array_sum- 2*(s2)=target_sum
   total_array_sum - target_sum =2*(s2)

   s2=(total_array_sum - target_sum)/2

   Problem Finally boils to calculate no. of subsets which has sum=s2
   if we find subset with s2 , automatically we have found subset with s1.

   So,its a Subset_sum_problem with:
   arraysize=n;
   targetsum=s2
     */
  int s1,s2;//let s1 be sum of first subset , s2 be sum of second subset

  s2=(sum - target)/2; //s2=(total_array_sum - target_sum)/2

  target=min(s2,sum-s2);

  int** dp=new int*[target+1];
  for(int row=0;row<=target;row++)dp[row]=new int[n+1];
  for(int i=0;i<=target;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;

  cout<<targetsum(arr,target,n,dp)<<endl;

  return 0;
}
