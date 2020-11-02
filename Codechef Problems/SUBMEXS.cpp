#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long int
#define endl "\n"


vector<int>adj[100005],children(100005);
int ans=INT_MIN,cnt=0; 

int subtree_dfs(int n) //count variable is not passed in the function becuase we
                       //have to add the count values and store them for each node.
                       //Here 'count' signifies no. of nodes in a particular subtree.
{
  int count=1;
  for(int i=0;i<adj[n].size();i++)
  {
     count+=subtree_dfs(adj[n][i]);
  }
  children[n]=count;
  return count;
}

int MEX_dfs(int n,int cnt) //cnt variable is passed in the function becuase
                           //we have to find the maximum value of cnt.
                           //if we will not pass it then we cant find maximum value of cnt.
                           //here cnt signifies no. of nodes under subtree of node 'n'.
{
  for(int i=0;i<adj[n].size();i++)
  {
     MEX_dfs(adj[n][i],cnt+children[adj[n][i]]);
  }
  ans=max(ans,cnt);
  return ans;
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    for(int i=0;i<100005;i++)adj[i].clear();
    children.clear();
    int n;
    cin>>n;
    int parent[n+1];
  

    for(int i=2;i<=n;i++)
    {
      cin>>parent[i];
      adj[parent[i]].push_back(i);
    }
    ans=INT_MIN,cnt=0; 

    subtree_dfs(1); //Running DFS from root node to every leaf node and 
                    //calculating number of nodes in a subtree of every node.

    cout<<MEX_dfs(1,children[1])<<endl; //Running DFS from root node to a every lead node.
                                        //and adding subtree size of particular node which
                                        //is coming on the path from root node to a 
                                        //particular leaf node and taking out the maximum sum 
                                        //among all the sums generated for each path from root node to leaf node.

}
  }
