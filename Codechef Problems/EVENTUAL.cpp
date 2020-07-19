#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>mp;
    for(int i=0;i<n;i++)
    {
      mp[s[i]]++;
    }
    int ok=0;
    for(auto i:mp)
    {
      if(i.second%2!=0)ok=1;
    }
    if(ok==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
