/*
Given a string consisting of only a and b, what is the minimum number of operationsneeded such that 
string doesn't contain 3 consecutive character which are same. 

In one operation you can replace a with b or replace b with a
[0-based indexing]
Input:aaaba -> 1 
Output: 1 (Replaced 'a' at index 2 with 'b' )
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
  string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  for(int i=0;i<n;i++)
  {
    int cnt=0;
    while((i+1)<n && s[i]==s[i+1]){i++;cnt++;}
    cnt++;
    ans+=cnt/3;
  }
  cout<<ans<<endl;
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
