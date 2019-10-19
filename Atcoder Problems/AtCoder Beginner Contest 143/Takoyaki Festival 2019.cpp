#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,a,ans=1,sum=0;
  cin>>n;
  vector<int>v;
  for(int i=0;i<n;i++)
  {
      cin>>a;
      v.push_back(a);
  }

  for(int i=0;i<n;i++)
  {
      for(int j=i+1;j<n;j++)
      {
          if(i!=j)
          {
              ans=v[i]*v[j];
              sum+=ans;
          }
      }
  }
  cout<<sum<<endl;
    return 0;
}
