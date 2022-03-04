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
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);

    int s1=a[0]+a[1],s2=a[n-1];
    int i=2,j=n-2;
    if(s2>s1){cout<<"YES"<<endl; continue;}
    
    int ok=0;
    while(i<j)
    {
      s1+=a[i];
      s2+=a[j];
      if(s1<s2){ok=1;break;}
      i++;
      j--;
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
    
    
