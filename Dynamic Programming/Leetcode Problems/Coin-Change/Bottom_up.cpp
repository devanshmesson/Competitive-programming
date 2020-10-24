class Solution 
{
  public:
    
    int coinChange(vector<int>& coins,int amount) 
    {
       int n=coins.size();
       int** dp=new int*[n+1];
        int sum=amount;
  for(int i=0;i<=n;i++)dp[i]=new int[sum+1];

  //Base Case in recursion = Initialization in Bottom up

  //Base Case:1 if(sum==0)return 0;
  for(int i=0;i<=n;i++)dp[i][0]=0;

  //Base Case:2 if(n==0 && sum!=0)return 1e9;
  for(int i=1;i<=sum;i++)dp[0][i]=1e9;

  //code the choice diagram
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(coins[i-1]<=j)
      {
        dp[i][j]=min(1+dp[i][j-coins[i-1]] , dp[i-1][j]);
      }
      else
      {
        dp[i][j]=dp[i-1][j];
      }
    }
  }

  if(dp[n][sum]==1e9)return -1;
  else return dp[n][sum];
   }
};
