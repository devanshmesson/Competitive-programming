#include<bits/stdc++.h>
using namespace std;
main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
  int n,k;
  cin>>n>>k;

  if(k>=n)
  {
    cout<<abs(k-n)<<endl;
  }
  else 
  {
    if(n%2==k%2)cout<<0<<endl;
    else cout<<1<<endl;
  }
 }
}
