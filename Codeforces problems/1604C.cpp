#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define int long long int
#define pb push_back
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    bool flag=1;
    int lcmnow=1;
    for(int i=1;i<=min(n,21ll);i++)
    {
      lcmnow = (lcmnow*(i+1))/__gcd(lcmnow,i+1);
      if(a[i]%lcmnow==0){flag=0;break;}
    }

    if(flag==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;


  }
}
 
