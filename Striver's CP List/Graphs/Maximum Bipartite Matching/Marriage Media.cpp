//Link - https://lightoj.com/problem/marriage-media

/*
Kuhn algorithm solves this problem - 
You are given a bipartite graph  containing  vertices and  edges. Find the maximum 
matching, i.e., select as many edges as possible so that no selected edge shares a 
vertex with any other selected edge.
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//Kuhn algorithm is used to maximize the pairs that can be matched with each other.
//Pair contains, one vertex from 1st set and 1 vertex from 2nd set.
//One vertex can be matched with only one vertex.
vector<int>man[51];
int mappedto[51];
vector<tuple<int,int,int>>boy,girl;
int visit[51];

int kuhn_algo(int n)
{
  if(visit[n]==1)return 0;
  visit[n]=1;
  for(int i=0;i<man[n].size();i++)
  {
    int woman=man[n][i];
    int heightgap=abs(get<0>(boy[n])-get<0>(girl[woman]));
    int agegap=abs(get<1>(boy[n])-get<1>(girl[woman]));
    int divorce=get<2>(boy[n])^get<2>(girl[woman]);
    int condition=heightgap<=12 && agegap<=5 && divorce==0;
    if(mappedto[woman]==-1 && condition==1){mappedto[woman]=n;return 1;}
    if(condition==1)
    {
      int approval=kuhn_algo(mappedto[woman]);
      if(approval==1){mappedto[woman]=n;return 1;}
    }
  }
  return 0;
}

signed main()
{
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    int m,n;
    cin>>m>>n;
    boy.clear();
    girl.clear();
    for(int i=0;i<m;i++){man[i].clear();}
    for(int i=0;i<n;i++){mappedto[i]=-1;}
   
    for(int i=0;i<m;i++)
    {
      int height,age,divorce;
      cin>>height>>age>>divorce;
      boy.pb({height,age,divorce});
    }
    for(int i=0;i<n;i++)
    {
      int height,age,divorce;
      cin>>height>>age>>divorce;
      girl.pb({height,age,divorce});
    }

    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)man[i].pb(j);
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
      memset(visit,0,sizeof(visit));
      ans+=kuhn_algo(i);
    }
    cout<<"Case "<<tt<<": "<<ans<<endl;

  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
*/ 
