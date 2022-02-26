/*
Find largest palindromic number formed by removing or shuffling digits from the number.
Microsoft Online Test!
*/
#include<bits/stdc++.h>
using namespace std;
signed main()
{
  string s;
  cin>>s;
  int n=s.size();
  map<int,int,greater<int>>hash;
  for(int i=0;i<n;i++)
  {
    hash[s[i]-'0']++;
  }
  if(hash.size()==1 && hash[0]>0){cout<<0<<endl; return 0;}
  char cen='a';
  string ans="";
  for(auto x: hash)
  {
    if(ans.size()==0 && x.first==0 && x.second>1)continue;
    int cnt=x.second/2;
    for(int i=0;i<cnt;i++)ans.push_back((char)x.first+48);
    if(x.second & 1==1 && cen=='a')cen=(char)x.first+48;
  }
  string rev=ans;
  reverse(rev.begin(),rev.end());
  if(cen!='a')ans+=cen;
  ans+=rev;
  cout<<ans<<endl;
}
