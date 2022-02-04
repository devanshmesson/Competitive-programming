#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif

#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

int nextt[1000000];
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m;
    cin>>m;
    int present[27]={0};
    int logg=0;
    
    //Calculating log(m)
    for(int i=1;(1<<i)<=(m-1);i++)logg=i;
    
    //Initializing nextt and present
    for(int i=0;i<n;i++){nextt[i]=-1;}
    for(int i=1;i<=26;i++)present[i]=-1;
    
    //Building nextt array(precomputation)
    for(int i=n-1;i>=0;i--)
    {
       int next_element=(s[i]-'a'+2)%27;
       if(next_element==0)next_element=1;
       int current=s[i]-'a'+1;
       if(present[next_element]!=-1)nextt[i]=present[next_element];
       present[current]=i;
    }
    int dp[n][logg+1];
    //Initializing dp array
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<=logg;j++)dp[i][j]=-1;
    }
    //Base cases
    for(int i=0;i<n;i++)dp[i][0]=nextt[i];
    
    //Builiding dp array
    for(int i=1;i<=logg;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(dp[j][i-1]==-1)continue;
        dp[j][i]=dp[dp[j][i-1]][i-1];
      }
    }

    int reset=logg;
  
    //for every 'a', traverse the subsequence in log(m) time
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='a')
      {
        int upd=i;
        int flag=1;
        int howmuchleft=m-1;
        logg=reset;
        while(howmuchleft>0)
        {
          int jump=(1<<logg);
          while(jump>howmuchleft)
          {
           logg--;
           jump=(1<<logg);
          }
          upd=dp[upd][logg];
          if(upd==-1){flag=0;break;}
          howmuchleft-=jump;
        }
        if(flag==0)continue;
        int subsequence_length=upd-i+1;
        int remove=subsequence_length-m;
        ans=min(ans,remove);
      }
    }
    ans==INT_MAX?cout<<-1<<endl:cout<<ans<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
