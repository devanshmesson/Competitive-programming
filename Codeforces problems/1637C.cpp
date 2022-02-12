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
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
  
    int odd=0,ev=0;
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
      if(a[i]%2==1)odd++;
      else ev++;
    }
    
    int ok=1;
    for(int i=1;i<n-1;i++)
    {
      if(a[i]!=1){ok=0;break;}
    }
    if(ok==1){cout<<-1<<endl;continue;}
    if(odd==1 && ev==0){cout<<-1<<endl;continue;}
    

    if(odd>=2 && ev==0)
    {
      int c=0;
      int v=0;
      for(int i=1;i<n-1;i++)
      {
        if(a[i]%2==1 && a[i]>1)
        {
          a[i]-=2;
          v=i;
          break;
        }
      }
       for(int i=1;i<n-1;i++)
      {
        if(a[i]%2==1 && v!=i)
        {
          a[i]++;
          break;
        }
      }
      odd--;
      ans++;
    }

    

    ans+=odd;
    a[0]+=odd;
    
    int cnt=1;
    int flag=0;
    for(int i=1;i<n-1;i++)
    {
     if(a[i]%2==1)
     {
      if(cnt<odd)a[i]--;
      else a[i]++;
      cnt++;
     }
     else if(flag==0 && odd>0)
     {
       a[i]-=2;
       flag=1;
     }
    }

    for(int i=1;i<n-1;i++)
    {
      ans+=(a[i]/2);
    }

    cout<<ans<<endl;




    

  }
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
