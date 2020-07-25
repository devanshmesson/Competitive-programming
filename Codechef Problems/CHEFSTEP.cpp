#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k,a;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
      cin>>a;
      if(a%k==0)cout<<1;
      else cout<<0;
    }
    cout<<endl;
  }
}
