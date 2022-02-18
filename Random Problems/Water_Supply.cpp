// https://leetcode.com/discuss/interview-question/1755940/de-shaw-online-assessment-water-supply
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
  
  int n,a;
  cin>>n;
  vector<int>v;
  for(int i=0;i<n;i++){cin>>a;v.pb(a);}
  
  int ans=0;
  while(1)
  {
    bool ok=true;
    for(int i=0;i<n;i++)
    {
        if(v[i]&1){v[i]--;ans++;}
    }
    for(int i=0;i<n;i++)
    {
       if(v[i]!=0)ok=false;
       v[i]/=2;
    }
    if(ok){break;}
    ans++;

  }
  cout<<ans<<endl;
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
