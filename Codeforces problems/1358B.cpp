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
  int n,a;
  cin>>n;
 map<int,int>mp;
  for(int i=0;i<(2*n);i++)
  {
    cin>>a;
    if(mp[a]==0)cout<<a<<" ";
    mp[a]++;
  }
  cout<<endl;
 } 
}
