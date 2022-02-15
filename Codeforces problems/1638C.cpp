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

bool sortbysec(const pair<int,int>a, const pair<int,int>b)
{
  if(a.first==b.first && a.second>b.second)return a<b;
  return a<b;
}


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
    int hash[n+1]={0};
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      hash[a[i]]=i;
    }
    int maxsmall[n+1]={0};
    maxsmall[1]=-1;
    maxsmall[2]=hash[1];
    int maxtillnow=max(hash[1],hash[2]);

    for(int i=3;i<=n;i++)
    {
       maxsmall[i]=maxtillnow;
       maxtillnow=max(maxtillnow,hash[i]);
    }
    
    int ans=1,upd=-1;
    for(int i=0;i<n;i++)
    {
      if(i>upd && i>0)ans++;
      upd=max(upd,maxsmall[a[i]]);
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
    
    
