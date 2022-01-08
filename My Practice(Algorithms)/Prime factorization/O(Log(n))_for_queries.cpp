#include<bits/stdc++.h>
using namespace std;

//considering n<=10^6
int spf[1000000];//smallest prime factor array

int precalculate_sieve(int n)
{
  //inintialize all elements equal to it's coresponding index
  for(int i=2;i<=n;i++)spf[i]=i;

  //Start sieve
  for(int i=2;i*i<=n;i++)
  {
    if(spf[i]==i) // it means i is a prime number
    {
      for(int j=i;j<=n;j+=i)
      {
        if(spf[j]==j)spf[j]=i; //if spf[j] is not changed, then change it.
      }
    }
  }
}

signed main()
{
  int query;
  cin>>query;
  precalculate_sieve(1000000);
  while(query--)
  {
    int n;
    cin>>n;
    while(n!=1)
    {
      cout<<spf[n]<<",";
      n/=spf[n];
    }
    cout<<"\n";

  }
}
