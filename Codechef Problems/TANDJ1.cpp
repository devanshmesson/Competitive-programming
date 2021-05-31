#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
main()
{
=  int t;
  cin>>t;
  while(t--)
  {
   int a,b,c,d,k;
   cin>>a>>b>>c>>d>>k;
   int h=abs(a-c)+abs(b-d);

   if(h>k){cout<<"NO"<<endl;continue;}

   if((k-h)%2==0)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
  }
}
