#include<bits/stdc++.h>
using namespace std;

#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define int long long int
main()
{
// 	freopen
	int t;
	cin>>t;
	while(t--)
	{
	   string s1,s2;
       cin>>s1>>s2;

      int n=s1.size(),m=s2.size();
      char s3[n+1],s4[m+1];

      for(int i=1;i<=n;i++)s3[i]=s1[i-1];
     for(int i=1;i<=m;i++)s4[i]=s2[i-1];

      vector<vector<int>>dp(n+1,vector<int>(m+1));
   
   //base case in recusrion=initilisation in bottom up

   //base case: if(n==0 || m==0)return 0;
   for(int i=0;i<=n;i++)dp[i][0]=0;
   for(int i=0;i<=m;i++)dp[0][i]=0;

  //code the choice diagram
    int result=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
         if(s3[i]==s4[j])
         {
           dp[i][j]=1+dp[i-1][j-1];
           result=max(result,dp[i][j]);
         }
         else 
         {
          result=max(result,max(dp[i-1][j],dp[i][j-1]));
         }
      }
    }


      int ans=n+m-(2*result);
       cout<<ans<<endl;
	}
}
