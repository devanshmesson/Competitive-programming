#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,b,m;
    cin>>n>>b>>m;
    int a[m+1];
    for(int i=0;i<m;i++)
    {
      cin>>a[i];
      a[i]++;
    }
    int upd; 
    upd=a[0]/b;
    if(a[0]%b==0)upd--;
    int ans=1;
    for(int i=1;i<m;i++)
    {
      int temp=upd;
      upd=a[i]/b;
      if(a[i]%b==0)upd--;
      //cout<<temp<<" "<<upd<<endl;
      if(temp!=upd)ans++;
    }
   cout<<ans<<endl;
  }
}
