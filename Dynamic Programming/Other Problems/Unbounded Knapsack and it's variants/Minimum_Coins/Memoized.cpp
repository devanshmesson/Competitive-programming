  
/*
Problem-Given a set of coins and a target sum.
Task-Find Minimum number of coins required to achive the required sum.
 This problem boils down to minimizing cost of adding item to knapsack.
 
 Cost of including every item=1.
 Capacity of knapsack=Target sum.
 weight array = set of coins.
 
 so,answer=min(include the item multiple times , not include the item)
 
 FILL THE KNAPSACK EQUAL TO THE CAPACITY.
 
*/

#include<bits/stdc++.h>
using namespace std;
 
int dp[110][1000010];
 
int coinchange1(int coin[],int n,int sum)
{
  //base condition
  if(sum==0)return 0;
  if(n==0 && sum!=0)return 1e9;

  //if already computed
  if(dp[n][sum]!=-1)return dp[n][sum];
 
  //choice diagram
  if(coin[n]<=sum)
  {
    return (dp[n][sum]=min(1+coinchange1(coin,n,sum-coin[n]),coinchange1(coin,n-1,sum)));
    
    /*
     2 ways to achieve the sum.
    
     Take minimum of answer of the 2 ways:
     way 1:include the item multiple items.
     way 2:not include the item.
     
     while including the item add 1 to the function call. '1' signifies that coin is included.
     while not including the item add nothing to the function call. 'Nothing' signifies that coin is not included.
     
    */
    
  }
  else
  {
    return dp[n][sum]=coinchange1(coin,n-1,sum);
  }
}
 
int main()
{
  int n,sum;
  cin>>n;
  int coin[n+1];
  cin>>sum;
  for(int i=1;i<=n;i++){cin>>coin[i];small=min(small,coin[i]);};
 
  for(int i=0;i<=n;i++)
  for(int j=0;j<=sum;j++)
  dp[i][j]=-1;
   
  int answer=coinchange1(coin,n,sum);
  if(answer==1e9)cout<<-1<<endl;
  else cout<<answer<<endl;
}
