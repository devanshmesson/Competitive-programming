include<bits/stdc++.h>
using namespace std;
#define pb push_back
main() 
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,a;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
      cin>>a;
      v.pb(a);
    }
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
      if(i==0 || i==n-1 || (v[i-1]<v[i])!=(v[i]<v[i+1]))ans.pb(v[i]);
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
      cout<<endl;
  }
  return 0;
}
