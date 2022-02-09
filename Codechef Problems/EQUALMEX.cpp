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
    n=2*n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    set<int>s;
    int mex=0,flag=1;
    int hash[n+10]={0};
    for(int i=0;i<n;i++)
    {
      hash[a[i]]++;
      s.insert(a[i]);
      if(a[i]+1!=s.size()){mex=s.size()-1;flag=0;break;}
    }
    if(flag==1)mex=a[n-1]+1;
    if(mex>n){cout<<"NO"<<endl;continue;}
    if(mex==0){cout<<"YES"<<endl;continue;}
    flag=1;
    for(int i=0;i<mex;i++)
    {
      int c=hash[i];
      if((c/2)<1){flag=0;break;}
    }
    if(flag==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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
