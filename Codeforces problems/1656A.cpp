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
    int x,y;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        if(mini>a[i])
        {
          mini=a[i];
          x=i;
        }
        if(maxi<a[i])
        {
          maxi=a[i];
          y=i;
        }
      }
    if(n==1){cout<<1<<" "<<1<<endl; continue;}
    cout<<x+1<<" "<<y+1<<endl;

    
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
    
    
