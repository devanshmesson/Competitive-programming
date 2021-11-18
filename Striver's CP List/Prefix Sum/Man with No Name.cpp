//Link -https://www.codechef.com/problems/BLONDIE
#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,sum=0;
    cin>>n;
    int a[n],prefix[n],ans[n];
    for(int i=0;i<n;i++)
    { 
      cin>>a[i];
      if(a[i]<0)a[i]=(prefix[i-1])/(i);
      sum+=a[i];
      prefix[i]=sum;
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }  
}
