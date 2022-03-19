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


signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int e=0,o=0;
    e+=(s[s.size()-1]-'0')%2==0;
    o+=(s[s.size()-1]-'0')%2==1;
    int flag=0;
    if(o==1)flag=1;
    else flag=0;
    for(int i=0;i<s.size()-1;i++)
    {
      int num=s[i]-'0';
      e+=(num%2==0);
      o+=(num%2==1);
    }
    if(flag==1 && o>=2)cout<<"YES"<<endl;
    else if(flag==0 && e>=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
