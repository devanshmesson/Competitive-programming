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
  // int u=1^1;
  // cout<<u<<endl;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    if(n==2){cout<<-1<<endl; continue;}
    if(n%2==0)
    {
      if(n==4){cout<<"1 4 2 3"<<endl;continue;}
      if(n==6){cout<<"5 2 3 6 4 1"<<endl;continue;}

      cout<<"2 1 3 4 6 7 5 8 ";
      for(int i=9;i<=n;i++)
      {
        cout<<i<<" ";
      }
      cout<<endl;

    }
    if(n%2==1)
    {
      for(int i=1;i<=n;i++)cout<<i<<" ";
      cout<<endl;
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
    
    
