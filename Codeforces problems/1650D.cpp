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
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    
    int ans[n+1];
    int ok=0;
    for(int i=n;i>=1;i--)
    {
      if(a[i]==i){ans[i]=0;continue;}
      // cout<<i<<" print:"<<endl;
      // for(int j=1;j<=n;j++){cout<<a[j]<<" ";}
      // cout<<endl;
      int pos;
      for(int j=1;j<=n;j++)
      {
        if(a[j]==i){pos=j; break;}
      }
      int dist;
      
      if(pos<i)dist=i-pos;
      else
      {
        ok=1;
        break;
      }
      ans[i]=i-dist;
      rotate(a+1, a+1+i-dist, a+i+1);
    }

    if(ok==1)
    {
      cout<<-1<<endl;
      continue;
    }

    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
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
    
    
