//Greedy Approach-Increment number of stores ,then Divide Number of people by number of stores and multiply this with the cost of each product , do this for all products and print the maximim answer.
#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
main()
{
  io
  int t;
  cin>>t;
  while(t--)
  {
    int n,s,p,v;
    cin>>n;
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
     cin>>s>>p>>v;
     ans=max(ans,(p/(s+1))*v);
    }
    cout<<ans<<endl;
  }
}
