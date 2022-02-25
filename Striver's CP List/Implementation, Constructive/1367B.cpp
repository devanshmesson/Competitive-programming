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
    int a[n];
    int odd=0,even=0;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        odd+=(a[i]%2==1);
        even+=(a[i]%2==0);
      }
    if(n%2==1 && ((n+1)/2)==even && (n/2)==odd);
    else if(n%2==1) {cout<<"-1"<<endl;continue;}
    
    if(n%2==0 && odd==even);
    else if(n%2==0) {cout<<"-1"<<endl;continue;}
    
    int cnt=0;
    for(int i=0;i<n;i++)
    {
      cnt+=(i%2!=a[i]%2);
    }
    cout<<cnt/2<<endl;
  }
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
