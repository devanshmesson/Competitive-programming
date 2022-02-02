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
    int flag=0,bits=0;
    for(int i=31;i>=0;i--)
    {
      int j=(1<<i);
      int res=n&j;
      if(res>0)bits++;
    }
    int a,b,c;
    vector<int>ans;
    if(bits==1)
    {
      int cnt=0;
      for(int i=0;i<=31;i++)
      {
        int j=(1<<i);
        int res=n&j;
        if(res==0)
        {
          cnt++;
          a=n|j;
          ans.pb(a);
        }
        if(cnt==2)break;
      }
      cout<<ans[0]<<" "<<n<<" "<<ans[1]<<endl;
    }
    else
    {
      int cnt=0;
      int whichbit;
      for(int i=0;i<=31;i++)
      {
        int j=(1<<i);
        int res=n&j;
        if(res>0)
        {
          cnt++;
          ans.pb(j);
          whichbit=i;
        }
        if(cnt==1)break;
      }

      int xorr=0;

      for(int i=0;i<=31;i++)
      {
        if(i==whichbit)
        {
          continue;
        }
        int j=(1<<i);
        int res=n&j;
        if(res>0)
        {
          xorr=xorr|j;
        } 
      }
      cout<<ans[0]<<" "<<xorr<<" "<<n<<endl;
    }
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
    */ 
