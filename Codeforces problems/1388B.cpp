/*
Problem-Given n which represents number of digits of a number 'x'.We have to find such 'x' that if we write binary representation of every digit (without leading zeroes)
       and concatenate them all and remove last n digits of this final binary number,This Binary number after removal of last n digits should be maximum possible if we 
       convert this binary number into decimal form.
      
For Ex- number - 729 number of digits(n)=3
      -binary equivalent of 7-111
      -binary equivalent of 2-10
      -binary equivalent of 9-1001
      Concatenate them all-111101001
      Remove last n digits from this binary number
      -Result-111101 (1+4+8+16+32=61)
      This Result should be maximized. This is the Problem.
     
Time Complexity-O(n)

Approach-To maximize the Result,We will choose greatest number of n digits and try to minimize it.
        -for ex-n=3
        -take number-999
        -binary equivalent-100110011001
        Result-100110011 (Removed last 3 digits)
        if we remove last 3 digits from this binary number then there is no use of the '1' at the 0th place.So instead of '1' we can change it to '0',
        and by doing so , our last number will become 8 instead of 9
        
        binaryequivalent of 998-100110011000
        Result-100110011 (Removed last 3 digits)
        As You see final result of 998 and 999 is same , so we  will choose 998 as we are asked to give minimal answer.
        Now you can see that we minimized our answer without changing the binary equivalant.
        
        if we take 997 
        binary equivalent-10011001111
        Result-10011001 (Removed last 3 digits)
        
        if se see Result of  997 is not maximum.so 998 is the minimal answer we get.
        
       
*/
#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    if(n==1){cout<<"8"<<endl;continue;}
    else 
    {
      int much=(n/4)+(n%4!=0);
      for(int i=0;i<n-much;i++)
      {
        cout<<"9";
      }
      for(int i=0;i<much;i++)cout<<"8";
      cout<<endl;
    }
  }
} 
