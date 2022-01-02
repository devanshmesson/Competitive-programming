#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

main()
{
  int n,q;
  cin>>n;
  int a[n],prefix[n],sum=0;
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
      sum+=a[i];
      prefix[i]=sum;
  }
  cin>>q;
  for(int i=0;i<q;i++)
  {
    int a,b;
    cin>>a>>b;
    if(a==0){cout<<prefix[b]<<endl; continue;}
    cout<<prefix[b]-prefix[a-1]<<endl;
  }  
}
