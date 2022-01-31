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
    int n;
    cin>>n;
    int y=n/10;
    int x=n%10;
    if(abs((2*x)-y)%7==0){cout<<n<<endl;continue;}
    int flag=1;
    for(int i=1;i<=9;i++)
    {
      if(abs(((2*i)-y))%7==0)
      {
        x=i;
        flag=0;
        break;
      }
    }
    if(flag==0)
    {
      cout<<y<<x<<endl;
    }
  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
    */ 
