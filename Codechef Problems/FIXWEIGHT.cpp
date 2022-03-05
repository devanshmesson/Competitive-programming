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
    int n,x;
    cin>>n>>x;
    if(x<=n){cout<<"YES"<<endl; continue;}
    int ok=0;
    for(int i=2;i<n;i++)
    {
      if(x%i!=0)continue;
      int div=x/i;
      div--;
      if(i+div<=n){ok=1;break;}
    }
    if(ok==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
  }
    
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
