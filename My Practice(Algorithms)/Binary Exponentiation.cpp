/*
Problem- To Calculate (base^power) in Log(power) time
Time Complexity-O(Log(Power))
Approach-To reduce the number of operations , we should focus on power
        -Naive Approach is O(power) because we multiplt base power times.
        -Optimized way would be If power is even then square the base and half the power
        -If Power is odd,we can write it as (base^(power-1))*base.In terms of code we will save this extra base in a variable named "ans" and power--;
        For Example-
        base=2  power=100 - 2^100    ans=1;
        base=4  power=50  - 4^50     ans=1;
        base=16 power=25  - 16^25    ans=1;
        base=16 power=24  - 16^24    ans=ans*16 => ans=16
        base=256 power=12 - 256^12   ans=16
        base=65536 power=6 -65536^6  ans=16
        base=4294967296 power=3      ans=16
        base=4294967296  power=2     ans=16*4294967296
        base=(4294967296)^2 power=1  ans=16*4294967296
        base=(4294967296)^2 power=0  Final ans=16*4294967296*(4294967296)^2

*/ 
#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  int base,power,ans=1;
  cin>>base>>power;
  
  while(power!=0)
  {
    if(power%2)
    {
      ans*=base;
      power--;
    }
    else
    {
      base*=base;
      power/=2;
    }
  }
  cout<<ans<<endl;
}
