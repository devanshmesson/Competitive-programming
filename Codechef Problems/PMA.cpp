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
    int a[n+1];
    for(int i=1;i<=n;i++){cin>>a[i];a[i]=abs(a[i]);}
    vector<int>od,ev;
    int oddsum=0,evsum=0;
    for(int i=1;i<=n;i++)
    {
      if(i%2==0)
      {
        ev.pb(a[i]);
        evsum+=a[i];
      }
      else {od.pb(a[i]); oddsum+=a[i];}
    }
    sort(ev.begin(),ev.end());
    sort(od.begin(),od.end());
    int ans=oddsum-evsum;

    int diff=ev[ev.size()-1]-od[0];
    if(diff<=0){ cout<<ans<<endl; continue;}


    oddsum+=diff;
    evsum-=diff;
    ans=oddsum-evsum;
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
    
    
