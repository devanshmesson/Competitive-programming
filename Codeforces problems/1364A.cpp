#include<bits/stdc++.h>
using namespace std;
#define pb push_back 
main() 
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x,a,ok=0;
    cin>>n>>x;
    vector<int>v;
    int sum=0;
    for(int i=0;i<n;i++){cin>>a;sum+=a;v.pb(a);if(a%x!=0)ok=1;}
    if(ok==0){cout<<-1<<endl;continue;}
    if(sum%x!=0){cout<<n<<endl;continue;}
    int in,ini;
    for(int i=0;i<n;i++)
    {
      if(v[i]%x!=0){in=i;break;}
    }
    for(int i=n-1;i>=0;i--)
    {
      if(v[i]%x!=0){ini=i;break;}
    }

    cout<<max(max(in,n-in-1),max(ini,n-ini-1))<<endl;
  }  
  return 0;
}
