/*
Problem - Given two numbers, n and k, Create an array with positive numbers whose sum is divisible by k, What should be the minimized value of the maximum number in the array.
Solution - 

if n==k : All elements will be 1.
if n>k && n%k==0 : all elements will be same.
if n>k && n%k!=0 : Find the minimized greater number than n which is divisible by k = n + k - n % k.
                 : Array will be in the form of (k - n % k) 2's and rest 1's.

if n<k : As number of elements are less than k,we can make an array whose sum is k.
       : First of all, fill 1's k/n times, some remaining sum will be k%n.
       : So minimized maximum element of array is (k/n)*1 + 1*(k%n).
       :                                      k/n times 1 + 1 time k%n.

*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
#define endl "\n"
main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,k;
      cin>>n>>k;
      if(n>k && n%k!=0){cout<<2<<endl;continue;}
      if(n>k && n%k==0){cout<<1<<endl;continue;}
      if(n==k){cout<<1<<endl;continue;}

      int g=k/n,ans=0;
      int h=k%n;

      if(h!=0)ans++;
      ans+=g;
      cout<<ans<<endl;

    }
}
