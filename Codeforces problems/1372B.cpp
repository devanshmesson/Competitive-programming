#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool yes(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
main() 
{
   io
   int t;
   cin>>t;
   while(t--)
   {
    int n;
    cin>>n;
    if(n%2==0)cout<<n/2<<" "<<n/2<<endl;
    else if(yes(n)==0)
    {
      int r=n/2;
      if(r%2==0)r--;
      int ans;
      for(int i=r;i>=sqrt(n);i-=2)if(n%i==0){ans=i;break;}
      cout<<ans<<" "<<n-ans<<endl;
    }
    else cout<<1<<" "<<n-1<<endl;
   }
  return 0;
}
