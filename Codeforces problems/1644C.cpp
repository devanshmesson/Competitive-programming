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
    int n,x;
    cin>>n>>x;
    vector<int>a(n),ans(n+1,INT_MIN);

    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=0;i<n;i++)
    {
      int sum=0;
      for(int j=i;j<n;j++)
      {
        sum+=a[j];
        int len=j-i+1;
        ans[len]=max(ans[len],sum);
      }
    }

    // for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    // cout<<endl;


   
    for(int i=0;i<=n;i++)
    {
      int add=i*x;
      int maxi=INT_MIN;
      for(int j=1;j<=n;j++)
      {
        int val;
        if(i<=j)val=ans[j]+add;
        else val=ans[j]+(j*x);
        maxi=max(maxi,val);
      }
      if(maxi<0)maxi=0;
      cout<<maxi<<" ";
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
    
    
