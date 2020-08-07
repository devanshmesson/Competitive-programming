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
    if(n==1 || n==2){cout<<n<<endl;continue;}
    if(n==3){cout<<2<<endl;continue;}
    if(n==5){cout<<3<<endl;continue;}
    int s=n/2;
    cout<<s+1<<endl;
  }
}
