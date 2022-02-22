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
    int a[n];
    if(n==3)
    {
      cout<<"3 2 1"<<endl;
      cout<<"3 1 2"<<endl;
      cout<<"2 3 1"<<endl;
      continue;
    }
    for(int i=0;i<n;i++)a[i]=n-i;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)cout<<a[j]<<" ";
      cout<<endl;
      rotate(a,a+n-1,a+n);
    }
  }
 


  
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
