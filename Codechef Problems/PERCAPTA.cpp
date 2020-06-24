#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    int a[n+1],b[n+1];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int maxper=INT_MIN;
    int per[n+1];
    for(int i=0;i<n;i++)
    {  
       scanf("%d",&b[i]);
       per[i]=a[i]/b[i];
       maxper=max(maxper,per[i]);
     }
      vector<int>adj[200005];
      for(int i=0;i<m;i++)
      {
        scanf("%d %d",&x,&y);
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
      }
     int visit[200005]={0};
     vector<int>an;
     for(int i=0;i<n;i++)
     {
       if(visit[i]==0 && maxper==per[i])
       {
        vector<int>ans;
        stack<int>s;
        s.push(i);
        visit[i]=1;
        ans.pb(i+1);
         while(!s.empty())
         {
          int d=s.top();
          s.pop();
          for(int j=0;j<adj[d].size();j++)
          {
            if(visit[adj[d][j]]==0 && maxper==per[adj[d][j]])
              {
                s.push(adj[d][j]);
                ans.pb((adj[d][j])+1);
                visit[adj[d][j]]=1;
              }
          }
         }
        int sz=ans.size();
        if(an.size()<sz)
        {
          an=ans;
        }
       }
     }
     int siz=an.size();
     printf("%d\n",siz);
     for(int i=0;i<siz;i++)
     {
      printf("%d ",an[i]);
     }
      printf("\n");
   }
}
