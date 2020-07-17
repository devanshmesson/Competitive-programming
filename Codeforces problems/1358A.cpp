#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int ar[3];
  for(int i=0;i<3;i++)cin>>ar[i];
  sort(ar,ar+3);
  int x,y,z;
  x=ar[0];
  y=ar[1];
  z=ar[2];
  int a,b,c;
  b=x;
  c=y;
  int d,f;
  if(c==z)
  {
    cout<<"YES"<<endl;
    cout<<min(b,c)<<" "<<b<<" "<<c<<endl;
  }
  else 
  {
    if(max(c,z)==z && max(b,z)==b)
    {
      cout<<"YES"<<endl;
      cout<<z<<" "<<b<<" "<<c<<endl;
    }
    else cout<<"NO"<<endl;
  }
 } 
}
