#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int d,n;
    cin>>d>>n;
    while(d--)
    {
      n=(n)*(n+1);
      n/=2;
    }
    cout<<n<<endl;
  }
}
