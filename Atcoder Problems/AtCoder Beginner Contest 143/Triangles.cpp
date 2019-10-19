#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,a,cnt=0;
  cin>>n;
  vector<int>v;
  for(int i=0;i<n;i++)
  {
      cin>>a;
      v.push_back(a);
  }
  sort(v.begin(),v.end(),greater<int>());
  for(int i=0;i<n;i++)
  {
      for(int j=i+1;j<n;j++)
      {
          for(int k=j+1;k<n;k++)
          {
              if(v[i]<v[j]+v[k] && v[j]<v[k]+v[i] && v[k]<v[i]+v[j])cnt++;
              else continue;
          }
      }
  }
  cout<<cnt<<endl;

    return 0;
}
