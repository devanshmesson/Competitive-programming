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


const int mod=1e9+7;

signed main()
{
  freopen
  ios

    int n,m;
    cin>>n>>m;
    int q[n+1];
    for(int i=1;i<=n;i++)cin>>q[i];
    vector<int>decompose[n+1];
    
    vector<int>store;

    for(int i=0;i<m;i++)
    {
      int dec,x;
      cin>>dec>>x;
      store.pb(dec);
      
      int bk;
      for(int j=0;j<(2*x);j++)
      {
        cin>>bk;
        decompose[dec].pb(bk);
      }
    }

    for(auto x: store)
    {
      int comp=x;
      int sz=decompose[comp].size();
      for(int i=0;i<sz-1;i+=2)
      {
        int wt=decompose[comp][i];
        int cp=decompose[comp][i+1];
        int addon=(q[comp]*wt)%mod;
        q[cp]=(q[cp]+addon)%mod;
      }
      q[comp]=0;
    }

    for(int i=1;i<=n;i++)cout<<q[i]<<endl;
    cout<<endl;
  }




    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
