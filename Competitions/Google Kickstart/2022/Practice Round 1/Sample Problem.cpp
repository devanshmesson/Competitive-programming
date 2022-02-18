// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

signed main()
{
  ios
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    int n,m;
    cin>>n>>m;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    int give=sum/m;
    int ans=sum-(give*m);
    cout<<"Case #"<<tt<<": "<<ans<<endl;
  }
}
