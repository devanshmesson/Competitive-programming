/*
Memoize the recursive solution.
Make a 2D matrix with Dimensions as the variables which change during recursion(in this case n and capacity).
Save the result of recursive function as dp[capacity][n] OR *(dp+capacity+n)
If dp[capacity][n] is not -1 then return that value and here you save calculation through DP
*/
#include<bits/stdc++.h>
using namespace std;

int knap(int weight[],int val[],int capacity,int n,int * dp) //Recieve 2D matrix in function as integer pointer
{
  //if already computed
  if(*(dp+capacity+n)!=-1)return *(dp+capacity+n); //Access 2D Matix cell through integer pointer as *(arrayname+row+column)
  
  /*Dimensions of matrix will be the variables which change during recursion*/
  
  //base condition
  if(n==0 || capacity==0)return 0; //zero number of items OR zero capacity

  //code the choice diagram
  if(weight[n]<=capacity) // can be included in knapsack
  { 
    return *(dp+capacity+n)=max(val[n]+knap(weight,val,capacity-weight[n],n-1,(int*)dp) ,//include the item
               knap(weight,val,capacity,n-1,(int*)dp));//dont include the item
  }
  else //cannot be included in the knapsack
  {
    return *(dp+capacity+n)=knap(weight,val,capacity,n-1,(int*)dp); //never include
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
  int dp[capacity+1][n+1];
  memset(dp,-1,sizeof(dp));
  cout<<knap(weight,val,capacity,n,(int*)dp)<<endl;  //Pass 2D matrix into function as integer pointer 
  return 0;
}
