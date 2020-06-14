#include<bits/stdc++.h>
using namespace std;
main() 
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    int ans=INT_MAX,ans1=INT_MAX;
    cin>>s;
    int num1=0,num0=0,done1=0,done0=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='1')num1++;
      else num0++;
    }
    ans1=min(num1,num0);
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='1')done1++;
      else done0++;
      ans=min(ans,min(done0+num1-done1,done1+num0-done0));
    }
    cout<<min(ans,ans1)<<endl;
  } 
  return 0;
}
