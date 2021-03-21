#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n,k,total=0;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){cin>>a[i];total+=a[i];}
    int mini=INT_MAX,sum=0;
    for(int i=1;i<=k;i++)sum+=a[i];
    mini=sum;
    
    for(int i=2;i<=(n-k+1);i++)  
    {
      sum-=a[i-1];   //sliding window
      sum+=a[i+k-1]; //sliding window
      mini=min(mini,sum);
    }
    int ans=0;
    ans=mini*(mini+1)/2;
    ans+=total-mini;
    cout<<ans<<endl;
  }
}
