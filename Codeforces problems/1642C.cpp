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
  for(int tt=1;tt<=t;tt++)
  {
    int n,x;
    cin>>n>>x;
    int a[n+1];
    map<int,int>mp;
    string s;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        mp[a[i]]++;
      }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++)
    { 
      int f1=a[i]*x;
      if(mp[a[i]]==0)continue;
      if(mp[f1]>0)
      {
        mp[f1]--;
        mp[a[i]]--;
      }
      else
      { 
        mp[a[i]]--;
        ans++;
      }

    }
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
    
    
