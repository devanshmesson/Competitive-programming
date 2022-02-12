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
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
      }

      int sum=0;
      int zeros=0;
      for(int i=0;i<n;i++)
      {
        zeros=0;
        for(int j=i;j<n;j++)
        {
          if(a[j]==0)zeros++;
          int len=j-i+1;
          sum+=len+zeros;
        }
      }
      cout<<sum<<endl;

  }
}
