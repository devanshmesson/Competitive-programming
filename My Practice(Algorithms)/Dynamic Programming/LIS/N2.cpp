//O(n^2) approach
#include<bits/stdc++.h>
using namespace std;

int LIS(int *a, int n)
{
  int lis[n]={0};
  lis[0]=1;
  for(int i=1;i<n;i++)
  {
    for(int j=i-1;j>=0;j--)
    {
      if(a[j]<a[i])lis[i]=max(lis[i],1+lis[j]);
    }
  }
  return lis[n-1];
}
signed main()
{
  int a[] = {1,1,1,1,2,2,3,3,4,6,4};
  int n=sizeof(a)/sizeof(a[0]);
  cout<<LIS(a,n)<<endl;
}
