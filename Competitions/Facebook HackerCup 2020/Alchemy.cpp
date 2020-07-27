#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
main()
{
  io
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    int n;
    cin>>n;
    string a;
    cin>>a;
    int h1=n/2,c1=0,c2=0;
    int h2=n-h1;
    for(int i=0;i<n;i++)
    {
      if(a[i]=='A')c1++;
      else if(a[i]=='B')c2++;
    }
    cout<<"Case #"<<tt<<": ";
    if(c1==h1 && c2==h2)cout<<"Y"<<endl;
    else if(c1==h2 && c2==h1)cout<<"Y"<<endl;
    else cout<<"N"<<endl;
  }
}
