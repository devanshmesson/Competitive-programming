#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	io
  string s;
  int c=0;
  cin>>s;
  sort(s.begin(),s.end());
  do
  {
    c++;
  }while(next_permutation(s.begin(),s.end()));
  cout<<c<<endl;
  //sort(s.begin(),s.end());
  do
  {
    for(int i=0;i<s.size();i++)cout<<s[i];
    cout<<endl;
  }while(next_permutation(s.begin(),s.end()));

}      

