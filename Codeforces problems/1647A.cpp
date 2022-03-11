// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
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
    int a[700];
    if(n==1){cout<<1<<endl; continue;}
    int sum=0;
    int ok=0;
    vector<int>ans;
    int cnt=0;
    for(int i=1;i<=700;i++)
    {
       if(i%2==1)a[i]=2;
       else a[i]=1;
       
       sum+=a[i];
       ans.pb(a[i]);
       if(sum==n){ok=1;break;}
       if(sum>n){ok=-1;break;}
    }
    if(ok==-1){cout<<1;ans.pop_back();}
    for(auto x: ans)cout<<x;
    cout<<endl;
  }
 
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
