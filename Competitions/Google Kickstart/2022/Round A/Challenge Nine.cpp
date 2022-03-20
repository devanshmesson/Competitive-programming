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
  ios
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    string s;
    cin>>s;
    int n=s.size();
    cout<<"Case #"<<tt<<": ";
    int sum=0;
    for(int i=0;i<n;i++)
    {
      int num=s[i]-'0';
      sum+=num;
    }
    if(sum%9==0)
    {
      cout<<s[0]<<0;
      for(int i=1;i<n;i++)cout<<s[i];
      cout<<endl;
    }
    else
    {
      int add=9*((sum/9)+1)-sum;
      int save=-1;
      for(int i=0;i<n;i++)if((s[i]-'0')>add){save=i;break;}
      if(save!=-1)cout<<s.substr(0,save)<<char(add+'0')<<s.substr(save,n-save+1)<<endl;
      else cout<<s<<char(add+'0')<<endl;
    }
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
