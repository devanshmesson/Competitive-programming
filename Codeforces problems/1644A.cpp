// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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
    int n=s.size();
    int hash[123]={0};
    // int n=s.size();
    int ok=0;
    for(int i=0;i<n;i++)
    {

      if(s[i]=='R' && hash[(int)'r']==0){ok=1;break;}
      if(s[i]=='G' && hash[(int)'g']==0){ok=1;break;}
      if(s[i]=='B' && hash[(int)'b']==0){ok=1;break;}

      if(s[i]=='r' || s[i]=='g' || s[i]=='b')hash[s[i]]++;
    }
    if(ok==1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
  
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
