//Same Explaination as in iterative approach
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int mod=1000000007;
int *dp={0};
int sol(int n)
{ 
   if(dp[n]!=0)return dp[n]%mod;
   if(n-3>=0)dp[n]=sol(n-1)%mod+sol(n-2)%mod+sol(n-3)%mod;
   return dp[n]%mod;
}
main()
{
  int t;
  cin>>t;
  dp=new int[100001];     //Saving memory
  while(t--)
  {
    int n;
    cin>>n;
    *dp=1;
    *(dp+1)=1;
    *(dp+2)=2; 
   cout<<sol(n)<<endl;
  }
  delete[] dp;
}
