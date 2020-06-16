#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
   int n,b,ans=0;
   cin>>n;
   vector<int>a;
   for(int i=0;i<n;i++){cin>>b;a.pb(b);}
   bool flag=1;

    for(int i=0;i<n;i++)if(i%2!=a[i]%2){flag=0;break;}
    if(flag){cout<<0<<endl;continue;}

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i!=j)
        {
          if(i%2!=a[i]%2 && j%2!=a[j]%2 && i%2!=j%2)
          {
            swap(a[i],a[j]);
            ans++;
          }
        }
      }
    }
    flag=1;
    for(int i=0;i<n;i++)if(i%2!=a[i]%2){flag=0;break;}
    
    if(flag)cout<<ans<<endl;
    else cout<<-1<<endl;


  }
}
