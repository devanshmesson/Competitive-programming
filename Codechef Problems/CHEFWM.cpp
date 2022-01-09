// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int prime_factorize(int n)
{
  if(n==1)return 0;
 int primes=0;
 for(int i=2;i*i<=n;i++)
 {
   if(n%i==0)
   {
       primes++;
     while(n%i==0)
     {
       n/=i;
     } 
   }
 }

 if(n>1)primes++;
 return primes;
}


signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    if(m==1){cout<<0<<endl;continue;}
    if(n==1){cout<<1<<endl;continue;}
    int primes=prime_factorize(m);
    while(1)
    {
      if(n%primes==0)break;
      primes--;
    }
    cout<<primes<<endl;
  }
}
