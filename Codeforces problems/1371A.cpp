#include<bits/stdc++.h>
using namespace std;
main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int n;
    cin>>n;
    if(n%2!=0)
    {
      n++;
      cout<<n/2<<endl;
    }
    else cout<<n/2<<endl;
   }
}
