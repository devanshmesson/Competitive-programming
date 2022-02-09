#include<bits/stdc++.h>
using namespace std;

int LIS(int *a, int n)
{
  if(n==0)return 1;
  int maxi=-1;
  for(int i=n-1;i>=0;i--)
  {
    if(a[i]<=a[n])
    {
      int lis=1+LIS(a,i);
      maxi=max(maxi,lis);
    }
  }
  return maxi;
}
signed main()
{
  int a[] = {1,1,1,1,2,2,3,3,4,6,4};
  int n=sizeof(a)/sizeof(a[0]);
  cout<<LIS(a,n-1)<<endl;
}
