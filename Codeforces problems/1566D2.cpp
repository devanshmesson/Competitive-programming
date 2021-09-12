#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
#define int long long int


main()
{
  freopen
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    unordered_map<int,int>mp;
    int a[m*n];
    vector<pair<int,int>>v;
    for(int i=0;i<m*n;i++)
      {
        cin>>a[i];
        v.push_back({a[i],i});
      }
    sort(v.begin(),v.end());
    
    for(int i=0;i<m*n;i++)
    {
      int x=v[i].second;
      mp[x]={i};
    }

    int ans=0;
    for(int i=1;i<(m*n);i++)
    {
      int col1=mp[i]%m;
      int row1=(mp[i]/m);

      for(int j=i-1;j>=0;j--)
      {
        int col2=mp[j]%m;
        int row2=(mp[j]/m);

        if(row1!=row2)continue;

        if(col2<col1 && v[mp[i]].first!=v[mp[j]].first)ans++;
      }
    }

    cout<<ans<<endl;
  }
}
