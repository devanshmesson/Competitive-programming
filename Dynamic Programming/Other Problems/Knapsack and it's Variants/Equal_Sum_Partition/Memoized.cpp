/*Partition the array such that sum of first partition = sum of second partition,print yes if its possible to partition the array in such a way */

#include<bits/stdc++.h>
using namespace std;

bool equalsum(int weight[],int target,int n,int **dp)
{
  //if already computed then no need to calcuate again, this is where we save time through Dynamic Programming
  if(dp[target][n]!=-1){return dp[target][n];}

  //Base case
  if(target==0)return 1;
  if(target!=0 and n==0)return 0;

  //Choice Diagram
  if(weight[n]<=target) //can include the item
  {
    return dp[target][n]=equalsum(weight,target-weight[n],n-1,dp) || equalsum(weight,target,n-1,dp);
  }
  else 
  {
    return dp[target][n]=equalsum(weight,target,n-1,dp);
  }

}


int main()
{
  freopen 
  io
  int n;
  cin>>n;
  int weight[n+1],sum=0;
  for(int i=1;i<=n;i++){cin>>weight[i];sum+=weight[i];}
 
  /*two partitions in equal amount can only happen if sum of the array is even*/
  if(sum%2==1){cout<<"Array cannot be divided into two sets"<<endl;return 0;}

  /*we will apply subset sum problem here with target=sum/2 
    because if one subset is found then the other subset will
    contain rest of the remaining elements summing up as sum/2*/

   int target=sum/2;

   //target=0 so there exist null set return 1
   //target!=0 and n==0 return 0;

   int **dp=new int *[target+1]; //dynamically allocate row pointers to 
                              //further allocate columns
   for(int row=1;row<=target;row++)
   {
     dp[row]=new int[n+1];
   }
   for(int i=1;i<=target;i++)for(int j=1;j<=n;j++)dp[i][j]=-1;
   if(equalsum(weight,target,n,dp)==1)cout<<"Array can be divided into two sets"<<endl;
   else cout<<"Array cannot be divided into two sets"<<endl;
  return 0;
}
