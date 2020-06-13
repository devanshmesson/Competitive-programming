#include<bits/stdc++.h>
using namespace std;
main() 
{
  int n,k,b;
  cin>>n>>k;
  vector<int>a;
  for(int i=0;i<n;i++){cin>>b;if(b>0)a.push_back(b);}
  sort(a.begin(),a.end());
  auto it=unique(a.begin(),a.end());
  a.resize(distance(a.begin(),it));
  int sum=a[0],temp=0;
  cout<<a[0]<<endl;
  for(int i=1;i<k;i++)
  {
    if(i>=(a.size())){cout<<0<<endl;continue;}
    cout<<a[i]-sum<<endl;
    sum+=a[i]-sum;
  }
 return 0;
}
