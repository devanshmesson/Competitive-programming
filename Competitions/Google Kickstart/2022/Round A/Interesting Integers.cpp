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

int check(int n)
{
  int prod=1,sum=0;
  int temp=n;
  while(temp>0)
  {
    int k=temp%10;
    temp/=10;
    prod*=k;
    sum+=k;
  }
  int res=prod%sum==0?1:0;
  return res;
}
signed main()
{
//   freopen
//   ios
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=a;i<=b;i++)
    {
      ans+=check(i);
    }
    cout<<"Case #"<<tt<<": "<<ans<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
