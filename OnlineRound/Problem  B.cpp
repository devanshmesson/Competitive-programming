#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {   
   int n,c;
   cin>>n;
   vector<int>b,a;
   for(int i=0;i<n;i++){cin>>c;a.pb(c);}
   for(int i=0;i<n;i++){cin>>c;b.pb(c);}
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0,ans=0;
    while(i<n && j<n)
    {
      if(a[i]>b[j]){i++;j++;ans++;}
      else if(a[i]<=b[j]){i++;}
    }
    cout<<ans<<endl;
  }
}
