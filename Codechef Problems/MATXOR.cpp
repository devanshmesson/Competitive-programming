#include<bits/stdc++.h>
using namespace std;
#define int long long int

int xored(int x)
{
  if(x%4==0)return x;
  if(x%4==1)return 1;
  if(x%4==2)return x+1;
  if(x%4==3)return 0;
}
main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    
    if(n==1 && m==1)
    {
      cout<<2+k<<endl;
      continue;
    }
    else if(n==1 || m==1)
    {
      int l=2+k;
      int r=n+m+k;
      int ans=xored(l-1)^xored(r);
      cout<<ans<<endl;
      continue;
    }
  

  int till;
  if(n%2==1)till=n-2;
  else till=n;

   for(int i=1;i<=till;i++)
    {
      int plus;
      if(i%2==1)plus=1;
      else plus=m;
      int g=i+plus+k;
      ans^=g;
    }
    
    if(n%2==0)
      {
        cout<<ans<<endl;
        continue;
      }

      if(n%2==1)
      {
        int a=n+1+k;
        int b=n+m+k;

        int f=xored(a-1)^xored(b);
        f^=(n-1+m+k);
        ans=ans^f;
        cout<<ans<<endl;
        continue;
      }
  }
}
