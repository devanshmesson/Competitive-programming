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
vector<int>a(200009),potential(200009);
int lis(int n)
{
  for(int i=0;i<n;i++)potential[i]=1e18;
  potential[0]=a[0];
  int upd=0;
  for(int i=1;i<n;i++)
  {
    auto x=lower_bound(potential.begin(),potential.begin()+upd+1,a[i]);
    int lbound=(x-potential.begin());
    if(lbound>=i)
    {
      lbound--;
    }
    if(potential[lbound]>=a[i] && lbound>0)lbound--;
    if(potential[lbound]>=a[i] && lbound==0)potential[lbound]=min(potential[lbound],a[i]);
    if(potential[lbound]<a[i])
    {
      int lis_length=lbound+1;
      potential[lis_length]=min(potential[lis_length],a[i]);
      upd=max(upd,lis_length);
    }
  }
  return upd+1;
}
signed main()
{
  freopen
  ios
  int n;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  cout<<lis(n)<<endl;
}
