#include<bits/stdc++.h>
using namespace std;
 
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int32_t main()
{
   long long int n;
   cin>>n;
   cout<<n<<" ";
   while(n!=1)
   {
       if(n%2!=0)n=(n*3)+1;
       else n/=2;
       cout<<n<<" ";
   }
}
