/*
Problem - Given a directed tree , make it a rooted directed tree by performing the following operation any number of times:
Remove a directed edge and add it anywhere in the graph to again make it a directed  tree.

Find out minimum number of operations to make the directed tree rooted.

A rooted directed tree is a directed tree in which we can directly/indirectly visit all vertices via only one vertex i.e. root vertex

Solution:-

Property of a tree is that indegree of every vertex in the tree is 1,except only one vertex(root).

Same property applies to the directed tree because:

1.it's not possible to reach every vertex via only one vertex.
2.A cycle can be made,in that case , that graph would not be a tree.

So, we have to make indegree of n-1 vertices = 1.
According to the operation specified , Answer will be: Sum of indegree of all vertices - 1 , if indegree >=1

lets take an example to understand the above formula in a better way: 

if indegree of a vertex is 10 , then to make its indegree to 1  we have to remove an edge and add that edge where the indegree of a vertex is 0.
The following operation has to be done 9 times to make its indegree to 1 becuase 9 incoming edges will be removed and that vertex will be left with only
one incoming edge and thus , making its indegree = 1.
*/

#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"

int main()
{
    io
    int t,n,a,b,indegree[10001]={0},sum=0;
    vector<int>v;
    cin>>t;
    while(t--)
    {
      cin>>n;
      v.clear();
      for(int i=1;i<=n;i++)indegree[i]=0;
      for(int i=0;i<n-1;i++)
      {
        cin>>a>>b;
        indegree[b]++;
        if(indegree[b]==1)v.pb(b);
      } 
      sum=0;
      for(auto x:v){sum+=indegree[x]-1;}
      cout<<sum<<endl;
    }
}
