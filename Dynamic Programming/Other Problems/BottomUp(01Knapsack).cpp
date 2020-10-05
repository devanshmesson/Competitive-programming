#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int weight[n+1],val[n+1],capacity;
  for(int i=1;i<=n;i++)cin>>weight[i];
  for(int i=1;i<=n;i++)cin>>val[i];
  cin>>capacity;
  int dp[capacity+1][n+1];
  
  //Base Case of Recursive Function=Initialization in Matrix

  //Base Case1 if n==0 then profit=0
  for(int i=0;i<=capacity;i++)dp[i][0]=0;
  //Base Case2 if capacity==0 then profit=0
  for(int i=0;i<=n;i++)dp[0][i]=0;

  //Code the Choice Diagram for every subproblem

  for(int i=1;i<=capacity;i++)
  {
    for(int j=1;j<=n;j++)
    {
       if(weight[j-1]<=i)  //Can include the item
       {
         dp[i][j]=max(val[j-1]+dp[i-weight[j-1]][j-1],dp[i][j-1]); //first-include , second-not include
       }
       else //Cannot include the item
       {
        dp[i][j]=dp[i][j-1]; // Never include the item
       }
    }
  }
  cout<<dp[capacity][n]<<endl; //last cell of the matrix is the answer
  return 0;
}
