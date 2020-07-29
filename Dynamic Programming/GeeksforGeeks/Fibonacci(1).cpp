/*
Problem-Find nth Fibonacci Number
Time Complexity-O(n)
Space Complexity-O(1)
Approach-Dynamic Programming - Bottom Up
        -Recursively calling the fibonacci function f[n-1] and f[n-2] costs us a huge complexity for lasrge numbers.
        -To Optimize we can updtae fibonacci for every index that comes on the way while solving for the nth fibonacci number.
        -This optimization will help in preventing us calculating fibonacci for an index that is asked again.
        -We can avoid the repeated work done by updating the Fibonacci numbers calculated so far.

*/
#include<bits/stdc++.h>
using namespace std;
main()
{
  int n,fibo1=0,fibo2=1,fibon;
  cin>>n;
  
  for(int i=2;i<n;i++)
  {
    fibon=fibo1+fibo2;
    fibo1=fibo2;
    fibo2=fibon;
  }
  cout<<fibon<<endl;
}
