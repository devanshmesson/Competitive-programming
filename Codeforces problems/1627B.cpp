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
    int n,m;
    cin>>n>>m;
    int a[4][2]={{1,1},{1,m},{n,1},{n,m}};
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=m;j++)
     {
       int ma=-1;
       for(int k=0;k<4;k++)
       {
         ma=max(ma,abs(i-a[k][0])+abs(j-a[k][1]));
       }
       v.push_back(ma);
     }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<=(n*m)-1;i++)cout<<v[i]<<" ";
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
    
    
    
    
    
