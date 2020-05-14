#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

int solve(int n,unordered_map<int,int>&dp)
{
    if(n==0)return 0;
    if(dp.count(n)){return dp[n];}
    return dp[n]=max(solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp),n);
}
main()
{
    int n;
    while(cin>>n)
    {
    unordered_map<int,int>dp;
    int ans=solve(n,dp);
    cout<<ans<<endl;
    }
}
