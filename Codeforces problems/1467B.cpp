#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define int long long int
int a[300001];
main()
{
    io
    int t,n,cnt,temp,sum=0,ans=INT_MAX,tm;
    cin>>t;
    while(t--)
    {
      cin>>n;
      cnt=0;
      for(int i=1;i<=n;i++)cin>>a[i];
      ans=INT_MAX;
      auto count=[&](int i)
      {
        if(i<=1 || i>=n)return 0;
        if(a[i]>a[i-1] && a[i]>a[i+1])return 1;
        else if(a[i]<a[i-1] && a[i]<a[i+1])return 1;
        else return 0;
      };
      for(int i=2;i<=n-1;i++)cnt+=count(i);
      ans=min(ans,cnt);
      for(int i=1;i<=n;i++)
      {
        temp=a[i];
        sum=0;
        sum+=count(i);
        sum+=count(i-1);
        sum+=count(i+1);
        tm=sum;
        if(i>1)
        {
         a[i]=a[i-1];
         sum-=count(i);
         sum-=count(i-1);
         sum-=count(i+1);
         ans=min(ans,cnt-sum);
        }
        a[i]=temp;
        sum=tm;
        if(i<n)
        {
         a[i]=a[i+1];
         sum-=count(i);
         sum-=count(i-1);
         sum-=count(i+1);
         ans=min(ans,cnt-sum);
        }
        a[i]=temp;
      }
      cout<<ans<<endl;
    }
}
