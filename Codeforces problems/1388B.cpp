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
      -Result-111101    
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
