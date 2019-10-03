#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int a;
  vector<int> v;
  for(int i=0;i<4;i++)
  {
      cin>>a;
      v.push_back(a);
  }
  sort(v.begin(),v.end());
  if(v[3]==v[0]+v[1]+v[2]){cout<<"YES"<<endl;return 0;}
  else if(v[3]+v[0]==v[1]+v[2]){cout<<"YES"<<endl;return 0;}
  else {cout<<"NO"<<endl;return 0;}
    return 0;
}
