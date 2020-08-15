#include<bits/stdc++.h>
using namespace std;
main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
  int n,m,k,a;
  cin>>n>>m>>k;
  map<int,int>mp;
  for(int i=1;i<=n;i++)mp[i]=0;
  for(int i=0;i<m;i++){cin>>a;mp[a]++;}
  for(int i=0;i<k;i++){cin>>a;mp[a]++;}
  int a1=0,a2=0;
  for(auto x:mp)
  {
    if(x.second>=2)a1++;
    else if(x.second==0)a2++;
  }
  cout<<a1<<" "<<a2<<endl;
 } 
}
