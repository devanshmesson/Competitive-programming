#include<bits/stdc++.h>
using namespace std;

int sieve[1000000]={0};
int perform_sieve(int n)
{
  for(int i=2;i<=n;i++)
  {
    if(sieve[i]==0)
    {
     for(int j=2*i;j<=n;j+=i)
     {
       sieve[j]=1;
     }
    }
  }
  for(int i=2;i<=n;i++)
  {
    if(sieve[i]==0)cout<<i<<" ";
  }
}

signed main()
{
  freopen
  perform_sieve(1000000);
  
}
