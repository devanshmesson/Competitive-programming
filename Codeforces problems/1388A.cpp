/*
Problem-Given n , Find Four different integers in which at least of them should be product of two prime numbers.If its possible to find such four number print YES Otherwise NO
Time Complexity-O(1)
Approach-Observation is problem is saying that at least 3 numbers should be product of two prime numbers.So it means the 4th number can be any random number 
         other than these 3 numbers.
         
         -After above point, what three points should we choose such that it can fulfill all the test cases?
         -Obviousuly we can take minimum three numbers which can be represented as product of two prime numbers ie. 2*3 , 2*5 , 2*7 ie.6 , 10, 14
         -4th Number can be decided by substracting from the input number. i.e n-(6+10+14)
         
         -There's a catch which we can lose here?Guess What?
         -What we will do when n-(6+10+14) i.e Fourth Number  , is one of those three numbers (6 , 10 , 14).Then Condition of 4th different numbers will be violated.
         -In that case we can change the third number to (3*5=15) instead of (2*7=14).Because 15 is the minimum possible number after 6 10 14.
         -So we will print 6 10 15 n-(6+10+15).
     
         -What will be the numbers for which there exist no Such case of 4 different numbers?
         -Obviosuly, Numbers less than (6+10+14) cant be represented as 6 10 14 n-(6+10+14). as 6+10+14 > n violates the condition.
*/
#include<bits/stdc++.h>
using namespace std;
main()
{

  int t;
  cin>>t;
  while(t--)
  {
    int n,left;
    cin>>n;
    if(n==31)
      {
        cout<<"YES"<<endl;
        cout<<6<<" "<<10<<" "<<14<<" "<<1<<endl;
        continue;
      }
    if(n>31)
    {
      left=6+10+15;
      left=n-left;
      cout<<"YES"<<endl;
      if(left==6 || left==10 ||left==15)
      {
        left=6+10+14;
        left=n-left;
      cout<<6<<" "<<10<<" "<<14<<" "<<left<<endl;
      }
      else cout<<6<<" "<<10<<" "<<15<<" "<<left<<endl;
    }
    else 
    {
      cout<<"NO"<<endl;
    }
  }
}
