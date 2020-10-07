#include<bits/stdc++.h>
using namespace std;

bool knap(int weight[],int target,int n,int ** dp)
{
  //recursion ends at base case
  if(target==0)return 1; //base case 1
  if(n==0 && target!=0){return 0;} //base case 2

   //if already computed for that particular target value and n 
   if(dp[target][n]!=-1){return dp[target][n];}

  //code the choice diagram
  if(weight[n]<=target) //can include
  {
    return dp[target][n]=knap(weight,target-weight[n],n-1,dp) || knap(weight,target,n-1,dp);  /*include || not include*/
  }
  else //cannot include
  {
    return dp[target][n]=knap(weight,target,n-1,dp);
  }
}

int main()
{
  int n;
  cin>>n;
  int weight[n+1],target;
  for(int i=1;i<=n;i++)cin>>weight[i];
  cin>>target;
  int ** dp=new int * [target+1];  //Dynamically allocate rows first
  for(int row=0;row<=target;row++)
  {
    dp[row]=new int[n+1];  //Dyanamically allocate columns for every row
  }
  for(int i=0;i<=target;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;
  if(knap(weight,target,n,(int**)dp)==1)cout<<"There exists a subset which has sum="<<target<<endl;
  else cout<<"No such subset exists which has sum="<<target<<endl;
  return 0;
}
