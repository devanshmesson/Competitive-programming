#include<bits/stdc++.h>
using namespace std;
#define int long long int

int height[100001];
int visit[100001];
int isleaf[100001];
int dfs(int n, int cnt,vector<int>graph[])
{
   for(int i=0;i<graph[n].size();i++)
   {
      int child=graph[n][i];
      if(visit[child]==0)
      {
       visit[child]=1;
       dfs(child,cnt+1,graph);
      }
   }
   //detecting leaf nodes
   if(graph[n].size()==1 && n!=1){isleaf[n]=1;}
   height[n]=cnt;
}

signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){height[i]=visit[i]=isleaf[i]=0;}
    vector<int>graph[n+1];
    for(int i=0;i<n-1;i++)
    {
      int u,v;
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    int sec[m+1];
    for(int i=0;i<m;i++)cin>>sec[i];
    visit[1]=1;
    dfs(1,0,graph);
    int maxdist=-1;
    int leafnodes=0;
    for(int i=1;i<=n;i++) maxdist=max(maxdist,height[i]);
    int leaves[maxdist+1]={0};
    int dropsonroot[maxdist+1];
    for(int i=1;i<=n;i++)
    {
      if(isleaf[i]==1){leaves[height[i]]++;leafnodes++;}
    }
    int prevsum=0;
    //calculating no. of leaves on root at ith second after reset.
    dropsonroot[1]=0;
    for(int i=2;i<=maxdist;i++)
    {
      int newdrops=0;
      newdrops+=leaves[i-1]+prevsum;
      dropsonroot[i]=dropsonroot[i-1]+newdrops;
      prevsum+=leaves[i-1];
    }
    
    int prev=0,ans=0;
    for(int i=0;i<m;i++)
    {
      int dur=sec[i]-prev;
      if(dur<maxdist)
      {
        ans+=dropsonroot[dur];
      }
      else
      {
        ans+=dropsonroot[maxdist];
        ans+=(dur-maxdist)*leafnodes;
      }
      prev=sec[i];
    }
    cout<<ans<<endl;
    
  }   
}
/*1.Never overkill a problem.
 2.think of test cases to clarify the approach/doubts.
*/ 
