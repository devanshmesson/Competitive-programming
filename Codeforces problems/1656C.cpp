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
    int y=0;
    int z=0,o=0,two=0;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      y+=(a[i]%2);
      if(a[i]==0)z++;
      if(a[i]==1)o++;
      if(a[i]==2)two++;
    }
    if(y==0 || y==n){cout<<"YES"<<endl; continue;}
    if(z>0 && o>0){cout<<"NO"<<endl;continue;}
    if(two>0 && o>0){cout<<"NO"<<endl;continue;}
    if(o==0){cout<<"YES"<<endl;continue;}
    sort(a,a+n);
    int ok=1;
    for(int i=0;i<n-1;i++)
    {
      if(a[i+1]-a[i]==1){ok=0;break;}
    }
    if(ok==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
    
    
