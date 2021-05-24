#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define endl "\n"
#define freopen freopen("input.txt","r",stdin);freopen("output1.txt","w",stdout);
#define pb push_back

int mod=1000000007;
int n;
vector<int>visit(2001,0);
int dist[2001][2001];


void dfs(int n,int cnt,vector<int>adj[],int start)
{
 // cout<<"n="<<n<<endl;
 // cout<<"cnt="<<cnt<<endl;
  for(auto x: adj[n])
  {
    // cout<<"x="<<x<<endl;
    // cout<<"visit["<<x<<"]="<<visit[x]<<endl;
    if(visit[x]==0)
    {
      dist[start][x]=cnt+1;
      dist[x][start]=cnt+1;
      // cout<<"dist["<<start<<"]["<<x<<"]="<<dist[start][x]<<endl;
      visit[x]=1;
      // cout<<"called with cnt="<<cnt+1<<endl;
      dfs(x,cnt+1,adj,start);
    }
  }

}

main()
{
//   freopen
  int t;
  cin>>t;
  while(t--)
  {
    int k,a;
    cin>>n>>k>>a;
    int special[k+1];
    int minsp=INT_MAX,maxsp=INT_MIN;
    for(int i=1;i<=k;i++)
      {
        cin>>special[i];
        minsp=min(minsp,special[i]);
        maxsp=max(maxsp,special[i]);
      }
    vector<int>adj[n+1];
    
    int flag=1;
    int x,y;
    for(int i=1;i<=n-1;i++)
    {
      cin>>x>>y;
      int b;
      if(x==i && y==i+1)b;
      else flag=0;
      if(n<=2000)
      {
        adj[x].push_back(y);
        adj[y].push_back(x);
      }
    }
  
    int ans[n+1],reason[n+1];


    if(flag==0)
    {
     //clearing visit vector
    for(int i=1;i<=n;i++)visit[i]=0;
    //clearing distance matrix
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dist[i][j]=0;
    //Precompute::
    //------------------
    for(int j=1;j<=k;j++)
      {
        int start=special[j];
        // int dest=a;
        for(int i=1;i<=n;i++)visit[i]=0;
        visit[start]=1;
        dfs(start,0,adj,start);
      }
    //-----------------


    //for each b
    for(int i=1;i<=n;i++)
    {
      //for each special node 'u'
      int maxi=INT_MIN,specmax;
      for(int j=1;j<=k;j++)
      {
        int start=special[j];
        int dist1=dist[start][a];
        int dist2=dist[start][i];

        int fin=dist1-dist2;
        if(maxi<fin)
        {
          maxi=fin;
          specmax=start;
        }
      }
      ans[i]=maxi;
      reason[i]=specmax;
    }

    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<reason[i]<<" ";
    cout<<endl;
 
   }
   else if(flag==1)
   {
     for(int i=1;i<=n;i++)
     {
 

      int dist1,dist2;

      if(a>=i)
      {
       dist1=abs(minsp-a);
       dist2=abs(minsp-i);
      ans[i]=dist1-dist2;
      reason[i]=minsp;
      }
      else 
      {
       dist1=abs(maxsp-a);
       dist2=abs(maxsp-i);
       ans[i]=dist1-dist2;
       reason[i]=maxsp;
      }

      // ans[i]=dist1-dist2;
      // reason[i]=specmax;
    }

    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<reason[i]<<" ";
    cout<<endl;

    }

  }
  
  
}
    
