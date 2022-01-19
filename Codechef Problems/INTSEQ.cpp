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
    int k;
    cin>>k;
    int upd=0,ans=0;
    while(1)
    {
      int val=k-upd;
      if(val%2==0)
      {
          ans++;
          upd+=val/2;
      }
      else break;

    }
    cout<<ans<<endl;

  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
*/ 
