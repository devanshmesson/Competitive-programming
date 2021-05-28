#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int>adj[100005];
int p[100005][21],h[100005],xorr[100005][21],value[100005];
vector<pair<int,int>>query;
int dfs(int cur,int prev)
{
	p[cur][0]=prev;
	h[cur]=h[prev]+1;

	for(auto x:adj[cur])
	{
		if(x==prev)continue;
		dfs(x,cur);
	}
}

int lca(int u,int v)
{
	//make the height of u,v equal

	//considering v as the deeper node, if not, then following
	//condition will handle the other case.

	int ans=0;

	if(h[u]>h[v])swap(u,v);
	int diff=h[v]-h[u];
  
    for(int i=0;i<=20;i++)
    {
    	if((diff & (1<<i))!=0)
    	{
          ans^=xorr[v][i];
          v=p[v][i];
    	}
    }
  
    if(u==v)return ans^xorr[u][0];

    
    for(int i=20;i>=0;i--)
    {
    	if(p[u][i]!=p[v][i])
    	{
    		ans^=xorr[u][i];
    		ans^=xorr[v][i];
    		u=p[u][i];
    		v=p[v][i];
    	}
    }
    return ans^xorr[u][0]^xorr[v][0]^xorr[p[u][0]][0];
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    	int n,q,u,v;
    	cin>>n>>q;
    	for(int i=1;i<=n;i++){cin>>value[i];xorr[i][0]=value[i];}
    	for(int i=1;i<=n;i++){adj[i].clear();h[i]=0;}

    	for(int i=1;i<n;i++)
    	{
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
    	}
    
    	dfs(1,0);

     
       
    	//xorr[i][j]=xor of values from ith node to ((2^j)-1)th

    	for(int i=1;i<=20;i++)
    	{
    		for(int j=1;j<=n;j++)
    		{
    			p[j][i]=p[p[j][i-1]][i-1];


    			int firsthalf=xorr[j][i-1];
                int pr=p[j][i-1];
                int secondhalf=xorr[pr][i-1];
    			xorr[j][i]=firsthalf ^ secondhalf;
    		}
    	}

    	
    	for(int i=0;i<q;i++)
    	{
    	    cin>>u>>v;
    		cout<<lca(u,v)<<endl;
    	}
    }
}
