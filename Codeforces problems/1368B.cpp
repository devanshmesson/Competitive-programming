#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  int a[]={1,1,1,1,1,1,1,1,1,1};
  string ans="codeforces";
  if(t==1){cout<<ans<<endl;return 0;}
  int subs=1,i=0;
  
  while(1)
  {
    subs=(subs/a[i]);
    a[i%10]++;
    subs*=a[i];
    i++;
    i%=10;
    if(subs>=t)break;
  }
  for(int i=0;i<10;i++)
  for(int j=0;j<a[i];j++)
  cout<<ans[i];
 }
