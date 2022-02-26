/*
Given string str containing only a and b, find the longest substring of str such that str does not contain more than two contiguous occurrences of a and b.
*/
#include<bits/stdc++.h>
using namespace std;
signed main()
{
  string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  int a=0,b=0;
  int l=0,r=0;
  int flag=0;
  for(int i=0;i<n;i++)
  {
    flag=0;
    r=i;
    a+=s[i]=='a';
    b+=s[i]=='b';

    if(s[i]=='b')a=0;
    else if(s[i]=='a')b=0;

    if(a==3)
    {
      ans=max(ans,r-l);
      l=r-1;
      a--;
      flag=1;
    }
    else if(b==3)
    {
      ans=max(ans,r-l);
      l=r-1;
      b--;
      flag=1;
    }
  }
  if(flag==0)ans=max(ans,r-l+1);
  cout<<ans<<endl;
}
