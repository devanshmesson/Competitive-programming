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

int lnds(vector<int>&a,int n)
{
  vector<int>potential(n,1e18);
  potential[0]=a[0];
  int maxi=0;
  for(int i=1;i<n;i++)
  {
    int lbound=upper_bound(potential.begin(),potential.end(),a[i])-potential.begin();
    if(lbound==0){potential[0]=a[i];}
    else 
    {
     potential[lbound]=min(potential[lbound],a[i]);
     maxi=max(maxi,lbound);
    }
  }
  return maxi+1;
}
signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    cout<<lnds(a,n)+lnds(b,m)<<endl;
  } 
}
