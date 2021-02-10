#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define freopen freopen("input.txt","r",stdin);freopen("out.txt","w",stdout);
#define pb push_back
#define int long long int
#define endl "\n"


main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,k,sum=0,ans=-1;
      cin>>n>>k;
      int a[n+1];
      for(int i=1;i<=n;i++)cin>>a[i];
      if(k>=9809){cout<<-1<<endl;continue;}
  
      for(int j=1;j<=k;j++)
      {
        ans=-1;
        for(int i=1;i<n;i++)
        {
           if(a[i]<a[i+1])
           {
             ans=i;
             a[i]++;
             break;
           }
        }
      }
      cout<<ans<<endl;
    }
}
