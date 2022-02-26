/*
There are N blocks from 0 to N-1. Two frogs were sitting together on one block, They had a quarrel and need to jump away from one another. 
The frogs can only jump to another block if the height of the other block is greater than equal to the current one. 
You need to find the longest possible distance that they can possible create between each other, if they also choose to sit on an optimal starting block initially.

Microsoft Online Test!

example 1:
Given blocks [2,6,8,5] it should return 3 (starting block is 0 and right frog jumps to blocks[2] 

example 2:
Given blocks [1,5,5,2,6] it should return 4 (starting block is [3], left frog jumps to [1] and right frog to [4])
*/

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

  int n;
  cin>>n;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  int left[n]={0},right[n]={0};
  left[0]=0;
  right[n-1]=0;

  for(int i=1;i<n;i++)
  {
    if(a[i]<=a[i-1])left[i]=left[i-1]+1;
    else left[i]=0;
  }

  for(int i=n-2;i>=0;i--)
  {
    if(a[i]<=a[i+1])right[i]=right[i+1]+1;
    else right[i]=0;
  }

  int ans=INT_MIN;
  for(int i=0;i<n;i++)
  {
    ans=max(ans,left[i]+right[i]+1);
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
    
    
