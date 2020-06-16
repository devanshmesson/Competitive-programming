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
    int a[n+1];
    set<int>s;
     for(int i=0;i<n;i++)
      {
        cin>>a[i];
        s.insert(a[i]);
      }
      if(s.size()==1)
      {
       cout<<n/a[0]<<endl;
       continue;
      }
       sort(a,a+n);
      int sofar=0,ans=0;
      for(int i=0;i<n;i++)
      {
         if(sofar>=(a[i]-1)){ans++;sofar-=(a[i]-1);}
         else sofar++;
      } 
      cout<<ans<<endl;
  }
}
