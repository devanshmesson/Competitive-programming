#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define int long long int
main()
{
    io
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      cout<<9;
      int s=8;
      for(int i=1;i<n;i++){cout<<s%10;s++;}
      cout<<endl;
    }
}
