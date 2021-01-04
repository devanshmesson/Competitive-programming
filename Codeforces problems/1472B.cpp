#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"
int main()
{
    io
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
       int n,sum=0;
       cin>>n;
       int a[n+1];
       for(int i=1;i<=n;i++)
       {
        cin>>a[i];
        sum+=a[i];
       }
       if(sum%2==1){cout<<"NO"<<endl;continue;}

       int target=sum/2;

       int dp[n+1][target+1];

       //base case
       for(int i=1;i<=target;i++)dp[0][i]=0;
       for(int i=0;i<=n;i++)dp[i][0]=1;

       for(int i=1;i<=target;i++)
       {
        for(int j=1;j<=n;j++)
        {
          if(a[j]<=i)
          {
            dp[j][i]=dp[j-1][i-a[j]] | dp[j-1][i];
          }
          else 
          {
            dp[j][i]=dp[j-1][i];
          }
        } 
       }
       if(dp[n][target]==1)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
}
