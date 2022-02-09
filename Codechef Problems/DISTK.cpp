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
    int n,k;
    cin>>n>>k;
    if(n-k==0)
    {
      for(int i=1;i<=n;i++)cout<<1<<" ";
      cout<<endl;
      continue;
    }
    //k>n
    int left=k-n;
    int nex=2;
    int upd=1;
    int a[n+1]={0};
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
      int val=i*(i+1);
      val/=2;
      val-=i;
      
      if(val<=left)
      {
        a[i]=nex;
        upd=val;
      }
      else
      {
        int ex=left-upd;
        if(ex==0)a[i]=a[i-1];
        else a[i]=a[i-ex-1];
        break;
      }
      nex++;
    }

    for(int i=1;i<=n;i++)
    {
      if(a[i]==0)a[i]=a[i-1];
      cout<<a[i]<<" ";
    }
    
    cout<<endl;
    
  }
}
    /*1.Never overkill a problem.
      2.think of test ca
      ses to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
