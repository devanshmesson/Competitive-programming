#include <bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k,m,s=0;
    cin>>n>>k;
    int a[n+1];
    for(int i=0;i<n;i++){cin>>a[i];s+=a[i];}
    if(s%k==0)
      {
        cout<<0<<"\n";
        continue;
      }
    cout<<1<<"\n";
  }
}
