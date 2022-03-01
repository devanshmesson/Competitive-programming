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
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    int upper_limit=INT_MAX;
    int lower_limit=n;

    int sum=0,remainder_sum=n*(n+1)/2;
    set<int>dup;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      sum+=a[i];
      dup.insert(a[i]);
      if(a[i]>n)upper_limit=min(upper_limit,a[i]);
    }
    if(dup.size()<n){cout<<"NO"<<endl; continue;}
    if(upper_limit==INT_MAX){cout<<"YES "<<n+1<<endl; continue;}

    assert(upper_limit<=1e7);
    int temp=sum-remainder_sum;
    vector<int>possible_x;

    for(int i=1;i*i<=temp;i++)
    {
      if(temp%i==0)
      {
        if(temp/i==i)
        {
          if(i>lower_limit && i<upper_limit){possible_x.pb(i);}
        }
        else
        {
          int f1=i;
          int f2=temp/i;
          if(f1>lower_limit && f1<upper_limit)possible_x.pb(f1);
          if(f2>lower_limit && f2<upper_limit)possible_x.pb(f2);
        }                                                
      }
    }
    set<int>s;
    int ok=0,ans=0;
    for(auto x: possible_x)
    {
      ok=0;
      s.clear();
      for(int i=0;i<n;i++)
      {
        int res=a[i]%x;
        if(res>n || res==0){ok=1;break;}
        s.insert(res);
      }
      if(s.size()==n && ok==0){ans=x;break;}
    }
    
    if(ans!=0){cout<<"YES "<<ans<<endl;}
    else cout<<"NO"<<endl;
  }
  
 
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
