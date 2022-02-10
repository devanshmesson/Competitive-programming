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
int lis(vector<int>&a,int n)
{
  vector<int>potential(n,1e18);
  potential[0]=a[0];
  int maxi=0;
  for(int i=1;i<n;i++)
  {
    int lbound=lower_bound(potential.begin(),potential.end(),a[i])-potential.begin();
    if(lbound==0){potential[0]=a[i];}
    else if(potential[lbound-1]<a[i]) 
    {
      potential[lbound]=min(potential[lbound],a[i]);
      maxi=max(maxi,lbound);
    }
  }
  return maxi+1;
}


signed main()
{
  freopen
  ios
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int lis1=lis(a,n);
  cout<<lis1<<endl;
  
}
    /*1.Never overkill a problem.
      2.think of test ca
      ses to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
    
    
    
