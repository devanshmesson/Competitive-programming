/*
Given an integer N, return the smallest non-negative number whose individual digits sum upto N.
Microsof Online test!
*/
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

  int n;
  cin>>n;
  if(n==0){cout<<0<<endl; return 0;}
  int nine=n/9;
  string ans="";
  int add=n%9;
  if(add>0)ans+=(char)add+48;
  for(int i=0;i<nine;i++)ans+=(char)9+48;
  cout<<ans<<endl;
  

}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
