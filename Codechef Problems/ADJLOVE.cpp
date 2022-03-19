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
    int o=0,e=0;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        o+=(a[i]%2==1);
        e+=(a[i]%2==0);
      }
    if(o==0 || o==1){cout<<-1<<endl; continue;}
    if(o%2==1 && e==0){cout<<-1<<endl; continue;}
    vector<int>odd,even;
    for(int i=0;i<n;i++)
    {
      if(a[i]%2==0)even.push_back(a[i]);
      else odd.pb(a[i]);
    }
    int flag=0, till=o-1;
    if(o%2==1){flag=1; till=o-1;}
    else till=o;
    for(int i=0;i<till;i++)cout<<odd[i]<<" ";
    for(auto x: even)cout<<x<<" ";
    if(flag==1)cout<<odd[o-1]<<endl;
    else cout<<endl;
  }

}




    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
