#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
#define int long long int

int sieve[1000000]={0};
int perform_sieve(int n)
{
  for(int i=2;i*i<=n;i++) // because prime factors are below sqrt(n), so all the multiples will be marked.
                          // for ex,n=20, sqrt(n)=4, we will think that 5's multiples are left, but they are not left,
                          //10,15,20 are alredy marked. If 5 is included, then its of no use because it will start marking from 25.
  {
    if(sieve[i]==0)
    {
     for(int j=i*i;j<=n;j+=i)// starting from i*i because , from i*2 to i*(i-1), it's computed before by the previous i's.
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
