#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int gcd(int a,int b)
{
  if(b==0)return a;
  int prev_a=a;
  a=b;
  b=prev_a%b;
  gcd(a,b);
}
signed main()
{
  int n,x,maxi=INT_MIN;
  cin>>n;
  for(int i=0;i<n;i++)cin>>x,a[x]=1,maxi=max(maxi,x);
  int ans=0;
  //Checking for every i in range [1,maxi]
  for(int i=1;i<=maxi;i++)
  {
    if(a[i]==1)continue;
    int till=maxi/i;
    int hcf=0;
    for(int j=2;j<=till;j++)
    {
      int multiple=i*j;

      if(a[multiple]==1)
      {
        hcf=gcd(hcf,multiple);
      }
    }
    if(hcf==i)
    {
      a[i]=1;
      ans++;
    }
  }
   cout<<ans<<endl;
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
*/ 
