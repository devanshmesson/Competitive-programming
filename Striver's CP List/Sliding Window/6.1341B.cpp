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

// const int mod=1000000009;

signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int prefix[n]={0};
    prefix[0]=0;
    int sum=0;
    for(int i=1;i<n-1;i++)
    {
      if(a[i]>a[i-1] && a[i]>a[i+1])sum++;
      prefix[i]=sum;
    }
    prefix[n-1]=prefix[n-2];

    int maxi=INT_MIN;
    sum=prefix[k-2];
    int l;
     if(maxi<sum)
      {
        maxi=sum;
        l=1;
      }
    for(int i=k;i<n;i++)
    {
      sum=prefix[i-1]-prefix[i-k+1];
      if(maxi<sum)
      {
        maxi=sum;
        l=i-k+2;
      }
    }
    cout<<maxi+1<<" "<<l<<endl; 
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
*/
