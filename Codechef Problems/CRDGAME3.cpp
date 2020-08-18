#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    int a1=(a/9)+(a%9!=0);
    int b1=(b/9)+(b%9!=0);
    if(a1<b1)cout<<0<<" "<<a1<<endl;
    else cout<<1<<" "<<b1<<endl;
  }
}
