#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define int long long int
#define pb push_back
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0,upd=0;
    for(int i=1;i<=n;i++)
    {
      if(a[i]>(i+upd))
        {
          ans+=a[i]-(i+upd);
          upd+=a[i]-(i+upd);
        }
    }
    cout<<ans<<endl;

  }
}
