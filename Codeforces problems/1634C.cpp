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
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int prod=n*k;
    int o=prod/2,e=prod/2;
    int sum=(o/k)+(e/k);
    if(k==1)
    {
      cout<<"YES"<<endl;
      for(int i=1;i<=n;i++)cout<<i<<endl;
      continue;
    }
    if(n>sum){cout<<"NO"<<endl;continue;}
    cout<<"YES"<<endl;
    int ans[n+1][k+1];
    int a=1;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
      int check=o/k;
      if(check==0)a=2;
      for(int j=0;j<k;j++)
      {
        ans[i][k]=a;
        a+=2;
        o--;
        cout<<ans[i][k]<<" ";
      }
      cout<<endl;
    }
  }
}
    /*1.Never overkill a problem.
      2.think of test ca
      ses to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
