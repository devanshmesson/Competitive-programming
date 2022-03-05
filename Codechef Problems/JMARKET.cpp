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
    vector<int>v;
    int x,a,b,c;
    cin>>x;
    for(int i=0;i<3;i++){int z;cin>>z; v.pb(z);}
    sort(v.begin(),v.end());
    int ans=(x-1)*v[0] + v[1];
    cout<<ans<<endl;

  }
    
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
