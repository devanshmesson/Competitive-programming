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
    string orig=s;
    reverse(s.begin(),s.end());
    string rev=s;

    //calculate longest prefix of reversed string that is present as
    //subsequence in the input string

    int upd=0;
    bool ok=true;
    int ans=0;
    for(int i=0;i<rev.size();i++)
    {
      ok=true;
      for(int j=upd;j<orig.size();j++)
      {
        if(rev[i]==orig[j]){ans++;upd=j+1;ok=false;break;}
      }
      if(ok)break;
    }

    cout<<orig.size()-ans<<endl;



  }
}


    /*1.Never overkill a probl7em.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
