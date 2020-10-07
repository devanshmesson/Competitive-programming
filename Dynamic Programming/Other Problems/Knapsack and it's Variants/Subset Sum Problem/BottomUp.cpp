#include<bits/stdc++.h>
using namespace std;
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
  //Base case in recursion = Initialization of matrix in Bottom Up DP
  
  //Base case 1 - capacity=0 , ans=Yes
  for(int i=0;i<=n;i++)dp[0][i]=1;

  //Base case 2 - n==0 and target!=0 then No
  for(int i=1;i<=target;i++)dp[i][0]=0;

  //Code the choice diagram

  for(int i=1;i<=target;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(weight[j]<=i) //can include the item
      {
        dp[i][j]=dp[i-weight[j]][j-1] || dp[i][j-1]; /*include item || dont include the item*/
      }
      else  //cannot include the item
      {
        dp[i][j]=dp[i][j-1];
      }
    }
  }

  if(dp[target][n]==1)cout<<"There exists a subset which has sum="<<target<<endl;
  else cout<<"No such subset exists which has sum="<<target<<endl;
  return 0;
}
