#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define endl "\n"
 
main() 
{
  int n,x,ans=0;
  cin>>n>>x;
  int a[n+1];
  for(int i=0;i<n;i++){cin>>a[i];}
    sort(a,a+n,greater<int>());
  int i=0,j=n-1;
  while(i<=j)
  {
    if(a[i]+a[j]<=x && i!=j)
    {
      i++;j--;
      ans++;
    }
    else if(a[i]+a[j]>x && i!=j)
    {
      ans++;
      i++;
    }
    else if(i==j){ans++;break;}
  }
  cout<<ans<<endl;
}

