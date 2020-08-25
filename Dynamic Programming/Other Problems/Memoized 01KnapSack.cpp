/*
1)Think Recursively
2)Think base cases
3)Make Choice Diagram
4)Code 2 and 3
5)Memoize it just add 4 lines to make it a Dp.
*/

#include<bits/stdc++.h>
using namespace std;

int dp[101][1001]; //suppossed constraints to be this
int knapsack(int *wt,int *val,int n,int cap)
{
  //Base Condition - smallest valid input
  if(n==0 || cap==0)return 0;

  if(dp[n][cap]!=-1)return dp[n][cap]; //Dynamic Programing taking place

  //Code Choice Diagram
  if(wt[n-1]<=cap)
  {
    return dp[n][cap]=max((val[n-1]+knapsack(wt,val,n-1,cap-wt[n-1])),  //include item
              (knapsack(wt,val,n-1,cap)));                              //dont inlclude item
  }
  else
  {
    return dp[n][cap]=knapsack(wt,val,n-1,cap);   //never include that item
  }
}


main()
{ 
 int n,cap;
 cin>>n;
 int wt[n+1],val[n+1];
 for(int i=0;i<n;i++)cin>>wt[i];
 for(int i=0;i<n;i++)cin>>val[i]; 
 cin>>cap;
 memset(dp,-1,sizeof(dp));
 int maxprofit=knapsack(wt,val,n,cap);
 cout<<maxprofit<<endl;
}
