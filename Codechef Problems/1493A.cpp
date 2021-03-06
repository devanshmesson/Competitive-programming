#include<bits/stdc++.h>
using namespace std;
main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,k;
  cin>>n>>k;
  vector<int>ans;
  for(int i=k+1;i<=n;i++)ans.push_back(i);
  int has[n+1]={0};
  for(int i=k-1;i>=1;i--)
  {
    if(has[i]==0)ans.push_back(i);
    has[k-i]=1;
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)cout<<x<<" ";
  cout<<endl;
 }
}
