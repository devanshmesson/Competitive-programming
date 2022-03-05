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

// vector<int>isprime()




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
   int s=n;
   int a[n+1];
   for(int i=0;i<n;)
   {
     if(i+1<n)
     {
      a[i]=s;
      a[i+1]=s*2;
      s--;
      i+=2;
     }
     else {a[i]=s;i++;}
   }
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
    
    
