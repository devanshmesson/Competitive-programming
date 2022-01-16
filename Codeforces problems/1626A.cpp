#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int a[150]={0};
    vector<char>v,c;
    int hash[150]={0};
    for(int i=0;i<s.size();i++)
    {
        a[s[i]]++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(a[s[i]]==2 && hash[s[i]]==0){hash[s[i]]=1;v.pb(s[i]);}
        else if(a[s[i]]==1)c.pb(s[i]);
    }
    for(auto x:v)cout<<x;
    for(auto x:v)cout<<x;
    for(auto x:c)cout<<x;
    cout<<endl;
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
*/ 
