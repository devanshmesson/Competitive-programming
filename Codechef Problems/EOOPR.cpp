/*
Mainly,Task was to calculate Minimum number of steps needed to achieve an even sum , with one positive odd number(a) and one negative even number(b).
We cannot change a and b.
Find such two numbers and print number of steps.

Mathematically, n*odd_number - m*even_number = sum , You have to Minimize value of (n+m) i.e steps

Maximum 3 number of steps will be needed to achive even sum.
How?
as we know,
odd+odd=even
even-even=even

Approach 1: so,we will add 'a' 2 times which becomes an even number and then subtract 'b' from it , which will be our answer.A
Approach 2: Another case would be , if an odd number divides the target, then number of steps = target/oddnumber.

So answer will be Minimum(Approach 1 , Approach 2)

For example,
Test case is to make x to y, 
where x=5 y=41 , Target = y-x = 41-5 = 36

By Approach 1: 

take 'a'>Target, so a = 37 (must be odd)
Add a to x , x = 42----------------------------------------------------------------------(1 step) 
Add a to x , x = 79----------------------------------------------------------------------(1 step)
[odd+odd=even]

As we exceeded the target , we have to subtract a number from it which is b.
b= difference = x-y = 79 - 41 = 38
b= 38, which is even.
Subtract b from x , which comes out to be  41 ,i.e y --------------------------------(1 step)  [even-even=even]
x=x-b= 41 =y

Approach 1 took 3 steps.

--------------------------------------------------------------------------------------------------------------------------------
By Approach 2:
Largest odd number which divides 36 is 9.
How?
Keep on dividing 36 by 2 and stop when the number is odd.

Total number of steps: 36/9 = 4
----------------------------------------------------------------------------------------------------------------------------------
Answer=Minimum(Approach 1 , Approach 2) = Minimum(3,4) = 3
*/
#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define int long long int
#define endl "\n"

main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int x,y;
    cin>>x>>y;
    if(x==y){cout<<0<<endl;continue;}

    int z=y-x;
    int q=x-y;
    if(z>0 && z%2==1){cout<<1<<endl;continue;} 
    if(q>0 && q%2==0){cout<<1<<endl;continue;}
    if(q>0 && q%2==1){cout<<2<<endl;continue;}
    int flag=0;
    if(z>0 && z%2==0)
    {
      int d=z;
      while(1)
      {
        d/=2;
        if(d%2==1){flag=1;break;}
      }
      int r=3;
      if(flag==1){cout<<min(z/d,r)<<endl;continue;}
    }
  }
}
