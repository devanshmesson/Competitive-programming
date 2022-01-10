#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    int hash[n+1]={0};
    for(int i=0;i<n;i++)
    {
     cin>>a[i];
     while(a[i]>n)a[i]/=2;
    
     if(hash[a[i]]==0)hash[a[i]]=1;
     else 
     {
      while(a[i]>0)
      {
        a[i]/=2;
        if(hash[a[i]]==0){hash[a[i]]=1;break;}
      }
     }
   }
     int flag=0;
     for(int i=1;i<=n;i++)if(hash[i]==0){flag=1;break;}
     if(flag==1)cout<<"NO"<<endl;
     else cout<<"YES"<<endl;
  }
}
