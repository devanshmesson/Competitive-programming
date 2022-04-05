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
    int r,c;
    cin>>r>>c;
    cout<<"Case #"<<tt<<":"<<endl;
    int plus=1;
    int pipe=1;
    
    for(int i=0;i<r;i++)
    {
      plus=pipe=1;
      for(int j=0;j<(2*c)+1;j++)
      {
        if(i==0 && j<2){cout<<".";}
        else if(plus){cout<<"+";plus=0;}
        else {cout<<"-";plus=1;}
      }
      cout<<endl;
      for(int j=0;j<(2*c)+1;j++)
      { 
        if(i==0 && j<2){cout<<".";}
        else if(pipe){cout<<"|";pipe=0;}
        else {cout<<".";pipe=1;}
      }
      cout<<endl;
    }
    plus=1;
     for(int j=0;j<(2*c)+1;j++)
      {
        if(plus){cout<<"+";plus=0;}
        else {cout<<"-";plus=1;}
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
