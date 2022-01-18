#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif

#define pb push_back
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double
int a[1000001];
signed main()
{
  freopen
  ios
    int n;cin>>n;
    int m=-1,x;
    for(int i=0;i<n;i++)cin>>x,a[x]=1,m=max(m,x);
    //gcdpairs[k]=number of pairs with gcd k
    int gcdpairs[m+1],ans=0;
    for(int i=m;i>=1;i--)
    {
      int cnt=0;
      for(int j=i;j<=m;j+=i)cnt+=a[j];
      gcdpairs[i]=cnt*(cnt-1)/2;
      //Removing pairs having gcd 2*i,3*i,...,k*i to count pairs with gcd i.
      int multiples=0;
      for(int j=2*i;j<=m;j+=i)
      {
        gcdpairs[i]-=gcdpairs[j];
        multiples+=a[j];
      }
      if(gcdpairs[i]>=1 && a[i]==0)
      {
        ans++;
        a[i]=1;
        gcdpairs[i]+=multiples;
      }
    }
    cout<<ans<<endl;
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
*/ 
