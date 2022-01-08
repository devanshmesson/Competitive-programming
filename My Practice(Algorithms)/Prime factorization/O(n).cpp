#include<bits/stdc++.h>
using namespace std;

int prime_factorize(int n)
{
  int power=0;
  for(int i=2;i<=n;i++)
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
}

signed main()
{
  freopen
  int n;
  cin>>n;
  prime_factorize(n);
}
