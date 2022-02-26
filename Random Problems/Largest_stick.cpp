/*
Largest possible square for cut sticks:
want to cut sticks so that we achieve 4 sticks of the same length. (there can be leftover pieces). What is the longest square side that we can achieve?
-use this function def square(A, B)
Input: two integers A, B
Output: Return the side length of the largest square that we can have, if not possible function should return 0.

ex1:
Input: A = 13, B = 11
Output: function will return 5 because we can cut two sticks of length 5 from each of the given sticks.

ex2:
Input: Given A = 10, B = 21
Output: the function will return 7 because we can split the second stick B into three sticks of length 7 and shorten the first stick A by 3.

ex3:
Input: Given A = 2, B = 1
Output: the function will return 0 as it is not possible to make any square from the sticks provided

ex4:
Input: Given A = 1, B = 8
Output: the function will return 2 because we can cut stick B into 4 parts

Microsoft Online test
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
  int a=1,b=8;
  int l=0, r=(a+b)/4;
  
  if(r<1){cout<<0<<endl;return 0;}

  int ans=0;
  while(l<=r)
  {
    int mid=(l+r)/2;
    int s1=(a/mid);
    int s2=(b/mid);
    
    if(s1+s2>=4)
    {
      l=mid+1;
      ans=mid;
    }
    else if(s1+s2<4)
    {
      r=mid-1;
    }
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
    
    
