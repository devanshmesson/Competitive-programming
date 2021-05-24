#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define endl "\n"
#define pb push_back

int mod=1e9+7;
main()
{
     int n;
    cin>>n;
    int a[n+1];
    int sum=0;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    int q,u;
    cin>>q;
    // int flag=0;
    for(int i=0;i<q;i++)
    {
      cin>>u;
      sum=(((sum*2)%mod)+mod)%mod;
      sum=sum%mod;
      cout<<sum<<endl;
    }

  
  
}
    
