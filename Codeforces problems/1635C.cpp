// taskkill /IM "a.exe" /F
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
    int a[n+1];
    int sum=0;
    for(int i=0;i<n;i++)cin>>a[i];
    if(is_sorted(a,a+n)){cout<<0<<endl;continue;}
    if(a[n-2]>a[n-1]){cout<<-1<<endl; continue;}
    int neg=1e9*(-1),pos=1e9;
    if(a[n-2]==neg && a[n-1]==pos){cout<<-1<<endl; continue;}
    int xy=a[n-2]-a[n-1];
    bool ok=0;
    for(int i=n-3;i>=0;i--)
    {
       if(xy<=a[i+1])a[i]=xy;
       else {ok=true;break;}
    }
    if(ok){cout<<-1<<endl;continue;}
    cout<<n-2<<endl;
    for(int i=n-3;i>=0;i--)
    {
      cout<<i+1<<" "<<n-1<<" "<<n<<endl;
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
    
    
