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
    vector<int>local;
    for(int i=1;i<n-1;i++)
    {
      if(a[i]>a[i-1] && a[i]>a[i+1])local.push_back(i);
    }

    int s=local.size();
    if(s==0 || n<=2)
      {
        cout<<0<<endl;
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
        continue;
      }
    int ans=0;
    for(int i=0;i<s-1;)
    {
      int diff=abs(local[i]-local[i+1]);
      if(diff==2)
      {
        int index=local[i]+1;
        a[index]=max(a[local[i]],a[local[i+1]]);
        ans++;
        i+=2;
      }
      else i++;
    }
    for(int i=1;i<n-1;i++)
    {
      if(a[i]>a[i-1] && a[i]>a[i+1])
      {
        a[i]=max(a[i-1],a[i+1]);
        ans++;
      }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
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
    
    
