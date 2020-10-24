class Solution 
{
  public:
    
    int coinChange(vector<int>& coins,int amount) 
    {
       int small=1e9;
       int n=coins.size();
       sort(coins.begin(),coins.end());
       small=coins[0];
          
       int** dp=new int*[n+1];
       for(int i=0;i<=n;i++)dp[i]=new int[amount+1];
       
       for(int i=0;i<=n;i++)
       for(int j=0;j<=amount;j++)
       dp[i][j]=-1;

       int answer=coinchange1(coins,n,amount,dp);

       if(answer==1e9)return -1;
       else return answer;
   }

   int coinchange1(vector<int>& coins,int n,int sum,int** dp)
   {

   //base condition
  if(sum==0)return 0;
  if(n==0 && sum!=0)return 1e9;
       
  //if already computed
  if(dp[n][sum]!=-1)return dp[n][sum];

 
  //choice diagram
  if(coins[n-1]<=sum)
  {
    return dp[n][sum]=min(1+coinchange1(coins,n,sum-coins[n-1],dp),coinchange1(coins,n-1,sum,dp));
  }
  else
  {
    return dp[n][sum]=coinchange1(coins,n-1,sum,dp);
  }
 }
};
