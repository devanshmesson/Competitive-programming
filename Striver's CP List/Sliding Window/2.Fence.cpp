//Link - https://codeforces.com/contest/363/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
  int n,k;
  cin>>n>>k;
  int sum=0;
  int a[n+1];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(i<k)sum+=a[i];
  }
  int mini=sum,ans=0;
  for(int i=k;i<n;i++)
  {
    sum-=a[i-k];
    sum+=a[i];
    if(mini>sum)
    {
      mini=sum;
      ans=(i-k+1);
    }
  }
  cout<<ans+1<<endl;
}
/*1.Never overkill a problem.
 2.think of test cases to clarify the approach/doubts.
*/ 
