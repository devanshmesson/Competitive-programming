//Link - https://www.codechef.com/problems/CNTAR
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

const int sz=1e5+5;
const int mod=1e9+7;

vector<int>v[sz];
vector<int>visit(sz);
vector<int>order(sz);
int dp[sz][2];

int cycle_length=0;

int dfs(int n,int ord)
{
  order[n]=ord;
  int totalnodes=1;
  for(int i=0;i<v[n].size();i++)
  {
    int adj=v[n][i];
    if(visit[adj]==0)
    {
      visit[adj]=1;
      totalnodes+=dfs(adj,ord+1);
    }
    else if(ord>order[adj])
    {
      cycle_length=max(cycle_length,ord-order[adj]+1);
    }
  }
  return totalnodes;
}

int power(int b,int e)
{
  int ans=1;
  while(e>0)
  {
    if(e%2==0)
    {
      e/=2;
      b=(b*b)%mod;
    }
    else
    {
      e--;
      (ans*=b)%=mod;
    }
  }
  return ans;
}

void precomutation(int n, int m)
{
  //dp[i][1] means number of ways at ith index of a cycle when val[(i-1)th] index = val[1st index]
  //dp[i][0] means number of ways at ith index of a cycle when val[(i-1)th] index != val[1st index]

  dp[2][1]=0;
  dp[2][0]=m*(m-1);
  for(int i=3;i<=n;i++)
  {
    dp[i][0]=((dp[i-1][0]*(m-2))%mod + (dp[i-1][1]*(m-1))%mod)%mod;
    dp[i][1]=dp[i-1][0];
  }
}


signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int a[n+1];
    
    for(int i=1;i<=n;i++){v[i].clear(); dp[i][0]=0; dp[i][1]=1;}
    precomutation(n,m);

    visit.clear();
    visit.resize(n+1);
    order.clear();
    order.resize(n+1);

    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      v[i].pb(a[i]);
      v[a[i]].pb(i);
    }

    int ans=0;
    int res=1;
    //traversing each connected component
    for(int i=1;i<=n;i++)
    {
      if(visit[i]==0)
      {
        visit[i]=1;
        order.clear();
        cycle_length=0;
        int totalnodes=dfs(i,0);
        
        if(cycle_length>=3)
        {
          ans=dp[cycle_length][0];
          ans=(ans*power(m-1,totalnodes-cycle_length))%mod;
        }
        else 
        {
          ans=(m*power(m-1,totalnodes-1))%mod;
        }
        (res*=ans)%=mod;
      }

    }
    cout<<res<<endl;
  }
  
  
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!t
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
