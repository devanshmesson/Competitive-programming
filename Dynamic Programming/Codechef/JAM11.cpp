/*
Problem-There are n stairs,Calculate No. of ways to reach nth stair, given that we can climb 1,2 or 3 stairs in one move.
Time Complexity-O(T*N)
Approach-What will be the previous step before we reach nth stair?
        -On Previous Step, we would either be on n-1th stair or n-2th stair or n-3th stair.Because we can only climb 1,2 or 3 stairs in one move.
        -How many ways are there to reach nth stair if we are on n-1th stair or n-2th stair or n-3th stair? Answer = 1 beacuse(read above points)
        -How many ways are there to reach nth stair?
        Answer-
        Let-
        A-No. of ways to reach n-1th stair
        B-No. of ways to reach n-2th stair
        C-No. of ways to reach n-3th stair
        X-No. of ways to reach nth stair if we are on n-1th stair or n-2th stair or n-3th stair
        
        Final Answer= (A*X)+(B*X)+(C*X)
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  int t,mod=1000000007,n;
  cin>>t;
  int dp[100001];
  dp[0]=1;
  dp[1]=1;
  dp[2]=2;
  
  for(int i=3;i<=100000;i++)
  {
    dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
  }
  while(t--)
  {
    cin>>n;
    cout<<dp[n]<<endl;
  }
}
