#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
main() 
{
  int n;
  cin>>n;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  int sum=0;
  sort(a,a+n);
  for(int i=0;i<n;i++)sum+=abs(a[i]-a[n/2]);
  cout<<sum<<endl;
}
