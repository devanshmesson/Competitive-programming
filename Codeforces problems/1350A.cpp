#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int primeFactors(int n)
{
    int m=INT_MAX;
    while (n % 2 == 0)
    {
        n = n/2;
    }
    for (int i = 3; i*i <=(n); i = i + 2)
    {
        while (n % i == 0)
        {
          m= min(m,i);           
          n = n/i;
        }
    }
    if (n > 2){m=min(m,n);}
    return m;
}
int32_t main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       if(n%2==0)cout<<n+k*2<<endl;
       else
       {
         int g=primeFactors(n);
         int ans=n+g;
         cout<<ans+(k-1)*2<<endl;
       }


   }
}
