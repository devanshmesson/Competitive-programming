// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double
signed main()
{
  freopen
  ios
  int n,m,q;
  cin>>n>>m>>q;
  vector<int>v[n+1];
  int visited[n+1]={0};
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    v[a].pb(b);
    v[b].pb(a);
  }
  vector<int>nodes;
  while(q--)
  {
   int t,x;
   cin>>t>>x;
   if(t==3){ cout<<((visited[x]==0)?"NO":"YES")<<endl; continue;}
   if(t==1){if(visited[x]==0)nodes.pb(x);visited[x]=1; continue;}
   x=min(x,n-1);
   vector<int>temp;
   for(int i=0;i<nodes.size();i++)
   {
     queue<pair<int,int>>q;
     q.push({0,nodes[i]});
     while(1)
     {
       if(q.empty())break;
       int lev=q.front().first;
       int n=q.front().second;
       if(lev>=x)break;
       q.pop();
       for(int j=0;j<v[n].size();j++)
       {
        int adj=v[n][j];
        if(visited[adj]==0)q.push({lev+1,adj});
        visited[adj]=1;
       }
     }
     while(!q.empty())
     {
       temp.pb(q.front().second);
       q.pop();
     }
   }
   nodes=temp;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
