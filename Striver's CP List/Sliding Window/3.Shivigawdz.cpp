// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif

#define pb push_back
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
    int n,b,a;
    cin>>n>>b>>a;
    int ar[n+1];
    for(int i=0;i<n;i++)cin>>ar[i];
    float ans=-1.0;
    for(int k=a;k<=b;k++)
    {
      float sum=0;
      for(int i=0;i<k;i++)sum+=ar[i];
      float avg=sum/(float)k;
      ans=max(ans,avg);
      for(int i=k;i<n;i++)
      {
        sum-=ar[i-k];
        sum+=ar[i];
        avg=sum/(float)k;
        ans=max(ans,avg);
      }
    }
    cout<<setprecision(7)<<fixed<<ans<<endl;
  }
}
 /* 1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up.*/
