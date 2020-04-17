#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,a;
    cin>>m>>n;
    vector<int>coin;
    for(int i=0;i<m;i++)
    {
        cin>>a;coin.push_back(a);
    }
    sort(coin.begin(),coin.end());

    vector<vector<int>>dp(m+10,vector<int>(n+10));
    for(int i=0;i<m;i++)
    {
        dp[i][0]=1;
    }

    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(coin[i]>j)
             {
                 if(i-1<0){dp[i][j]=0;}
                 else {dp[i][j]=dp[i-1][j];}
             }
            else
            {
                if(i-1<0){dp[i][j]=dp[i][j-coin[i]];}
                else {dp[i][j]=dp[i][j-coin[i]]+dp[i-1][j];}
            }
            dp[i][j]=dp[i][j]%mod;
        }
    }
    cout<<dp[m-1][n];
}
