#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int sz=s.size();
    vector<char>v;
    int j=1;
    v.pb(s[0]);
    for(int i=1;i<(sz-1);i+=2)v.pb(s[i]);
    v.pb(s[(sz-1)]);
    for(int i=0;i<v.size();i++)cout<<v[i];
    cout<<endl;
  }
}
