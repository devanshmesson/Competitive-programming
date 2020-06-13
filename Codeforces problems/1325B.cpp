#include<bits/stdc++.h>
using namespace std;
main() 
{
  int t;
  cin>>t;
  while(t--)
  {
    int x;
    cin>>x;
    int a;
    set<int>s;
    for(int i=0;i<x;i++){cin>>a;s.insert(a);}
    cout<<s.size()<<endl;
  }
  return 0;
}
