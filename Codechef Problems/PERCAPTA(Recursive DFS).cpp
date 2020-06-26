#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
unordered_map<int,int>visit;
void dfs(int s,vector<int>&res,vector<int>adj[],int amax,int bmax,int a[],int b[])
{
  for(auto x:adj[s])
  {
    if(visit[x]==0 && a[x]*bmax==b[x]*amax)
    {
      visit[x]=1;
      res.push_back(x+1);
      dfs(x,res,adj,amax,bmax,a,b);
    }
  }

}
main() 
{
   int t;
   cin>>t;
   while(t--)
   {
     visit.clear();
     int n,m,u,v;
     scanf("%lld %lld",&n,&m);
     int a[n+1],b[n+1];
     vector<int>adj[n+1]; 
    
     for(int i=0;i<n;i++)scanf("%lld",&a[i]);
     for(int i=0;i<n;i++)scanf("%lld",&b[i]);
     for(int i=0;i<m;i++)
     {
      scanf("%lld %lld",&u,&v);
      u--;v--;
      adj[u].pb(v);
      adj[v].pb(u);
     }
     int amax=a[0],bmax=b[0];
     for(int i=1;i<n;i++)
     {
      if(bmax*a[i]>amax*b[i])
      {
        amax=a[i];
        bmax=b[i];
      }
     }
  
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
      if(visit[i]==0 && a[i]*bmax==b[i]*amax)
      {
        vector<int>res;
        visit[i]=1;
        res.push_back(i+1);
        dfs(i,res,adj,amax,bmax,a,b);
        if(ans.size()<res.size())ans=res;
      }
      
     }
     printf("%lld",ans.size());
    printf("\n");
    for(auto x:ans)printf("%lld ",x);
    printf("\n");     
   }
  }
