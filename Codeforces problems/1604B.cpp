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
    if(n%2==0){cout<<"YES"<<endl;continue;}
    int flag=0;
    for(int i=1;i<=n-1;i++)
    {
      if(a[i]>=a[i+1]){flag=1;break;}
    }
    if(flag==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
