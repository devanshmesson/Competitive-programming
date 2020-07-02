#include<bits/stdc++.h>
using namespace std;
main() 
{
  #define int long long int 
   int n;
   cin>>n;
   int a[n+1];
   int sum=0;
   for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
   if(sum%360==0){cout<<"YES"<<endl;return 0;}
   bool ok=1;
   for(int i=0;i<(1<<n);i++)
   {
    bitset<15>bits(i);
    sum=0;
    ok=0;
    for(int j=n-1;j>=0;j--)
    {
      if(bits[j])sum+=a[j];
      else sum-=a[j];
    }
    if(sum%360==0){ok=1;break;}
   }
   if(ok)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}
