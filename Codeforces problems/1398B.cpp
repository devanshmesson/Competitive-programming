#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
main()
{ 
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    int c=0;
    cin>>s;
    vector<int>ans;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='1')c++;
      else 
      {
        if(c>0)ans.pb(c);
        c=0;
      }
    }
    if(c>0)ans.pb(c);
    sort(ans.begin(),ans.end(),greater<int>());
    int much=ans.size()/2;
    if(ans.size()%2)
    {
      much++;
    }
    int cn=0;
    for(int i=0;i<ans.size();i+=2)
    {
      cn+=ans[i];
      much--;
      if(much==0)break;
    }
    cout<<cn<<endl;
  } 
}
