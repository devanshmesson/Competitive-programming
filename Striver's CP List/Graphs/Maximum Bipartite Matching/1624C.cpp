//Link - https://codeforces.com/contest/1624/problem/C
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int>graph[51];
int mappedto[51];
int visit[51];

int kuhn_algo(int index)
{
  if(visit[index]==1)return 0;
  visit[index]=1;
  for(int i=0;i<graph[index].size();i++)
  {
    int factor=graph[index][i];
    if(mappedto[factor]==-1){mappedto[factor]=index;return 1;}
    int approval=kuhn_algo(mappedto[factor]);
    if(approval==1){mappedto[factor]=index;return 1;}
  }
  return 0;
}
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
   int n;
   cin>>n;
   int a[n+1];
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++){graph[i].clear(); mappedto[i]=-1;}
   //building bipartite graph
   for(int i=1;i<=n;i++)
   {
     while(1)
     {
       if(a[i]<=n && a[i]>0)graph[i].pb(a[i]);
       a[i]/=2;
       if(a[i]<=0)break;
     }
   }
   int pairs_found=0;
   for(int i=1;i<=n;i++)
   {
     memset(visit,0,sizeof(visit));
     pairs_found+=kuhn_algo(i);
   }
   
   if(pairs_found==n)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;

  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
*/ 
