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
    int n,m;
    cin>>n>>m;
    char a[n+1][m+1];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        char x;
        cin>>x;
        a[i][j]=x;
      }
    }
    if(n==1 || m==1){cout<<"YES"<<endl; continue;}
    
    int ok=0;
    for(int i=0;i<n-1;i++)
    {
      ok=0;
      for(int j=0;j<m-1;j++)
      {
        int one=0,zero=0;
        one+=(a[i][j]=='1');
        zero+=(a[i][j]=='0');

        one+=(a[i][j+1]=='1');
        zero+=(a[i][j+1]=='0');

        one+=(a[i+1][j]=='1');
        zero+=(a[i+1][j]=='0');
        
        one+=(a[i+1][j+1]=='1');
        zero+=(a[i+1][j+1]=='0');

        if(one==3 && zero==1){ok=1;break;}
      }
      if(ok==1)break;
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
    
    
