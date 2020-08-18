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
    int ans=INT_MAX,final=-1;
    for(int i=0;i<n;i++)
    {
     cin>>a;
     if(k%a==0)
     {
       if(ans>=(k/a))
       {
        ans=k/a;
        final=a;
       }
     }
    }
    if(final>=1)cout<<final<<endl;
    else cout<<-1<<endl;
  }
}
