// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

int ispal(string &s, int i, int j)
{
  int n=s.size();
  while(i<j)
  {
    if(s[i]!=s[j])return 0;
    i++;
    j--;
  }
  return 1;
}
int check(string &s)
{
  // cout<<"hi "<<s<<endl;
  int n=s.size();
  for(int i=0;i<n;i++)
  {
    for(int j=i+4;j<n;j++)
    {
      int res=ispal(s,i,j);
      if(res==1){return 0;}
    }
  }
  return 1;
}

int choice(int i, int n, string &s)
{
  if(i==n)return check(s);
  if(s[i]=='0' || s[i]=='1')return choice(i+1,n,s);
  if(s[i]=='?')
  {
    string p=s;
    s[i]='1';
    p[i]='0';
    return choice(i+1,n,s) | choice(i+1,n,p);
  }
}
signed main()
{
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans;
    if(n<5){ans="POSSIBLE";cout<<"Case #"<<tt<<": "<<ans<<endl; continue;}
    if(choice(0,s.size(),s))ans="POSSIBLE";
    else ans="IMPOSSIBLE";
    cout<<"Case #"<<tt<<": "<<ans<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */  
