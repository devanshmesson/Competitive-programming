//Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1474
#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool prime[1000001];
int prefix[1000001];
void SieveOfEratosthenes(int n)
{
    for(int i=1;i<=1000000;i++)prime[i]=true;
    prime[0]=prime[1]=false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
int check(int n)
{
  int t=n,sum=0;
  while(t>0)
  {
    sum+=t%10;
    t/=10;
  }
  if(prime[sum]==true)return 1;
  return 0;
}
main()
{
  prefix[0]=0;
  SieveOfEratosthenes(1000000);
  int sum=0;
  for(int i=1;i<=1000000;i++)
  {
    if(prime[i]==true && check(i)==1)sum++;
    prefix[i]=sum;
  }
  int n;
  cin>>n;
  while(n--)
  {
    int a,b;
    cin>>a>>b;
    cout<<prefix[b]-prefix[a-1]<<endl;
  }
}
