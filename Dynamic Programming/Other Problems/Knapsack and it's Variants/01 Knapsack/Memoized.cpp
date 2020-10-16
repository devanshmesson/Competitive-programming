#include<bits/stdc++.h>
using namespace std;

int knap(int weight[],int val[],int capacity,int n,int ** dp) 
{
  //if already computed
  if(dp[capacity][n]!=-1)return dp[capacity][n];
  /*Dimensions of matrix will be the variables which change during recursion*/
  
  //base condition
  if(n==0 || capacity==0)return 0; //zero number of items OR zero capacity

  //code the choice diagram
  if(weight[n]<=capacity) // can be included in knapsack
  { 
    return dp[capacity][n]=max(val[n]+knap(weight,val,capacity-weight[n],n-1,dp) ,//include the item
               knap(weight,val,capacity,n-1,dp));//dont include the item
  }
  else //cannot be included in the knapsack
  {
    return dp[capacity][n]=knap(weight,val,capacity,n-1,dp); //never include
  }
}

int main()
{
  int n;
  cin>>n;
  int weight[n+1],val[n+1],capacity;
  for(int i=1;i<=n;i++)cin>>weight[i];
  for(int i=1;i<=n;i++)cin>>val[i];
  cin>>capacity;
  int ** dp;
  dp=new int*[capacity+1]; //Dynamically allocated rows
  for(int row=0;row<=capacity;row++)
  {
    dp[row]=new int[n+1]; //dynamically allocate column for each row
  }
  for(int i=0;i<=capacity;i++)
  {
    for(int j=0;j<=n;j++)
    {
      dp[i][j]=-1;
    }
  }
  cout<<knap(weight,val,capacity,n,dp)<<endl;  //Pass 2D matrix into function as integer pointer 
  return 0;
}
