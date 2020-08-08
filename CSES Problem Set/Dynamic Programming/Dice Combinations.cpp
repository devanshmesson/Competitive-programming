/*
Problem-Given a sum "n", You have a dice containing moves 1 to 6.In How many ways you can achieve sum "n" by playing with it any number of times.
Time Complexity-O(n)
Approach-Focus on the last move through we can achieve the required sum.
        -Last move would be 1,2,3,4,5,6.
        -If we know number of ways to achive sum n-1,n-2,n-3,n-4,n-5,n-6 then we are done with the problem.Wanna know How?
        Let's Assume:
        A-No. of ways to achieve sum n-1 (if last move is 6 )
        B-No. of ways to achieve sum n-2 (if last move is 5 )
        C-No. of ways to achieve sum n-3 (if last move is 4 )
        D-No. of ways to achieve sum n-4 (if last move is 3 )
        E-No. of ways to achieve sum n-5 (if last move is 2 )
        F-No. of ways to achieve sum n-6 (if last move is 1 )
        X[i]-[where "i" can be (A-F)],No. of ways to throw 1,2,3,4,5,6 (which is 1)
        
       Final Answer=(A*X)+(B*X)+(C*X)+(D*X)+(E*X)+(F*X)
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  int n,sum=1,mod=1e9+7;
  cin>>n;
  int dp[1000001]={0};
  dp[1]=1;
  for(int i=2;i<=6;i++)  //Calculating Values till dp[6]
  {
    dp[i]=sum+1;
    sum+=dp[i];
  }
  if(n<=6){cout<<dp[n]<<endl;return 0;}
  for(int i=7;i<=n;i++)   
  {
    dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%mod;
  }
  cout<<dp[n]<<endl;
}
