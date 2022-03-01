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

const int mod=998244353;

signed main()
{
  freopen
  ios

    int d;
    cin>>d;
    if(d%2==0)
    {
      // cout<<1<<" "<<2<<endl;
      // cout<<2<<" "<<3<<endl;
      // cout<<2<<" "<<1<<endl;
      // cout<<3<<" "<<2<<endl;
      int half=d/2;
      int x1,y1,x2,y2,x3,y3,x4,y4;

      x1=2;
      x2=x1+half;
      x3=x2;
      x4=d+2;

      y1=1e5;
      y2=y1+half;
      y3=y1-half;
      y4=y1;

      cout<<x1<<" "<<y1<<endl;
      cout<<x2<<" "<<y2<<endl;
      cout<<x3<<" "<<y3<<endl;
      cout<<x4<<" "<<y4<<endl;
    }
    else cout<<-1<<endl;

  
 
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
