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
  // freopen
  ios
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    string s;
    cin>>s;
    int n=s.size();
    int flag=0;
    int twice[n]={0};
    for(int i=n-1;i>=1;i--)
    {
     if(s[i]>s[i-1])
     {
       flag=1;
     }
     else if(s[i]<s[i-1])flag=0;
     if(flag==1 && s[i]>s[i-1])
     {
       twice[i-1]=1;
     }
     if(flag==1 && s[i]==s[i-1])
     {
       twice[i-1]=1;
     }

    }
    cout<<"Case #"<<tt<<": ";
    for(int i=0;i<n;i++)
    {
      if(twice[i]==1)cout<<s[i]<<s[i];
      else cout<<s[i];
    }
    cout<<endl;
  }
}


/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
