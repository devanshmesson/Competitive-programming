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
    int l,r,a;
    cin>>l>>r>>a;
    int ans=0;
    if(r>=a)
    {
      if(r%a==a-1)
      {
        ans=r/a + (r%a);
        cout<<ans<<endl;
        continue;
      }
      int q=r/a;
      int x=(a*q)-1;
      if(x<l)
      {
        if(abs(l-a)>abs(r-a))
        {
          x=l;
        }
        else x=r;
      }
     
      ans=x/a + (x%a);
      cout<<ans<<endl;
    }
    else
    {
      ans=r/a + (r%a);
      cout<<ans<<endl;
      continue;
    }


  }
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
