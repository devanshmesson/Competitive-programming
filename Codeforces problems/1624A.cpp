// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
#define int long long int


signed main()
{
//   freopen
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    
    sort(a,a+n);
    int ans=0;

    int addon=0;
    for(int i=n-2;i>=0;i--)
    {
      int d=a[n-1]-a[i]-addon;
      addon+=d;
      if(d>0)ans+=d;
    }
    cout<<ans<<endl;
  }
}
