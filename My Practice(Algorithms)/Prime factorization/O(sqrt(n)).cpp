#include<bits/stdc++.h>
using namespace std;

int prime_factorize(int n)
{
  int power=0;
  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
      power=0;
      while(n%i==0) //keep on dividing it with i
      {
        n/=i;
        power++;
      }
      cout<<i<<"^"<<power<<",  ";
    }
  }
  //last prime factor having power as 1
  if(n>1)cout<<n<<"^"<<1; 
}

signed main()
{
  int n;
  cin>>n;
  prime_factorize(n);
}
