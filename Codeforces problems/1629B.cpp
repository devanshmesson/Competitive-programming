
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
    int l,r,k;
    cin>>l>>r>>k;
    int len=r-l+1;
    // cout<<len<<endl;
    if(len==1 && l>1){cout<<"YES"<<endl;continue;}
    if(len%2==0 && k>=(len/2)){cout<<"YES"<<endl;continue;}
    if(len%2==1)
    {
      //even
      int f=((len-1)/2);
      if(l%2==0 && k>=f){cout<<"YES"<<endl;continue;}
      int g=len/2;
      g++;
      if(l%2==1 && k>=g){cout<<"YES"<<endl;continue;}
    }
    cout<<"NO"<<endl;

  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
*/ 
