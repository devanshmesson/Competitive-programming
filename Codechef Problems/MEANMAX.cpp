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
   float a[n+1];
   for(int i=0;i<n;i++)cin>>a[i];
   sort(a,a+n);
   float sum=0;
   for(int i=0;i<n-1;i++)
   {
    sum+=a[i];
   }

   float s1=sum/(n-1);
   s1+=a[n-1];
   cout<<setprecision(7)<<fixed<<s1<<endl;
 }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
*/ 
