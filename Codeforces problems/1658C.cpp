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

const int mod=998244353;
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
    int one=0;
    for(int i=0;i<n;i++){cin>>a[i]; one+=a[i]==1;}
    if(one!=1){cout<<"NO"<<endl; continue;}
    if(n==1 && a[0]==1){cout<<"YES"<<endl; continue;}
    else if(n==1){cout<<"NO"<<endl; continue;}
    int flag=0;
    for(int i=0;i<n;i++)
      {
        if(a[(i+1)%n]<=a[i] || a[(i+1)%n]==(a[i])%n+1);
        else {flag=1; break;}
      }
    if(flag==0){cout<<"YES"<<endl; continue;}
    cout<<"NO"<<endl;

   }
}

/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
    
    
