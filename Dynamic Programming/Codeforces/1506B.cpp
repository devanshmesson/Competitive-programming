#include<bits/stdc++.h>
using namespace std;

#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define int long long int
#define endl "\n"

int dp[51][51],k;
string s;

int help(int *star,int current, int prev, int init)
{
  //base condition
  if(current==-1)
  {
  	if(abs(init-prev)<=k)return 0;
  	else return 1e12;
  }

  if(dp[star[current]][prev]!=-1)return dp[star[current]][prev];

  //choice diagram
  //choice:1 Convert the particular '*' into 'x'
  //choice:2 Do not convert the particular '*' into 'x'

  if(abs(star[current]-prev)<=k)
  {
     return dp[star[current]][prev]=min(1+help(star,current-1,star[current],init),help(star,current-1,prev,init));
  }
  else 
  {
    return dp[star[current]][prev]=help(star,current-1,prev,init);
  }
}
main()
{
	int t;
	cin>>t;
	while(t--)
	{
      int n;
      cin>>n>>k;
      cin>>s;
      int fi,si;
      for(int i=0;i<n;i++)if(s[i]=='*'){fi=i;break;}
      for(int i=n-1;i>=0;i--)if(s[i]=='*'){si=i;break;}

      if(fi==si){cout<<1<<endl;continue;}
      if(abs(fi-si)<=k){cout<<2<<endl;continue;}

      for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;
      
      int cnt=0,star[n+1];
      for(int i=0;i<n;i++)
      {
      	if(i==fi || i==si)continue;
        if(s[i]=='*')star[cnt++]=i;
      }
      cout<<help(star,cnt-1,si,fi)+2<<endl;
	}
}
