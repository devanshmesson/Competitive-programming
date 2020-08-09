/*
Problem-You are given some number(n) of coins with different values,Find minimum number of coins(we can use a coin any no. of times) which sum to given number "sum".
Time Complexity-O(n*sum)
Approach-Focus on the last move after which we will get the required sum.
        -Last move will obviously contain coins among the given coins.
        -We have to think in a way such that if the last move after which we will get the required sum is A[i](input array),then our problem reduces to 
         find minimum number of coins which will sum to "sum-a[i]" and this process continues.
         
         Example for explaining the above lines:
           n=3 sum=11
input_array-1 5 7 <-"a"
           
           Considering last move to be 1:This means we have already achieved sum=10
           We have to find minimum number of coins which sum to 10 (Subproblem)
           
           Case 1: summing 1 ten times.
                  ans1=10+1 ("+1" is for adding the "last move" which is also 1)
           
           Case 2:adding 5,Now problem reduces to achieve 5 , which can be achieved by adding another 5.
                 ans2=5+5+1=3
                 
           Case 3:adding 7, Now Our Problem reduces to achieve 3,which is only achieved 1+1+1
                 ans3=7+1+1+1+1=5 
                 
           So mimimum number of coins which can sum to 11 is 3 if our input array is 1 5 7 .
           
           Two More Cases:
           
           Considering last move to be 5:This means we have already achieved sum=6.
           Considering last move to be 7:This means we have already achieved sum=4.
           
           
           As you observed that problems got reduced to either 10 or 6 or 4.
           Now as we observed we applied same steps to these 3(10 or 6 or 4).
           
          
          Thinking Recursively is easy in this, but i was not able to implement recursively,Prefer to do iterativley.
          
          How to do iteratively?
          
          As we observed that problem got reduced to subproblems containing 10,6,4 and now recursively we can call 10 and 6 and 4, but wait iterative approach 
          is more cool and easy.
          
          Instead of recursively caling 10,6,4 which will further be  also creating subproblems for 10,6,4  [9,5,3 for 10].
          Why not calculate minimum number of coins which have sum starting from 1 till our "target sum" and calculate value taking in account every coin to be lastmove one by one
          and taking out the minimum one.
          
          Hindi- "1 se leke target sum tak saari values nikal lo beforehand"
          
          This way we already have the numbers which we were asking to calculate recursively!
          For Example,
          if we were to calculate minimum no. of coins for 11 which have input array 1 5 7.
          For 11 we needed 10,6,4 which we already have in our dp array named "coins".
          
          So this way we are using Dyanamic Programming by Storing Values beforehand instead of doing it recursively!
 
*/ 

#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  int n,sum;
  cin>>n>>sum;
  vector<int>a(n+1);
  for(auto &v:a)cin>>v;   //A very cool way of inputting in vector. "&" is important in this.
  vector<int>coins(1000001,1e9);   //Our dp array being initialized to 1e9, if the asked value is still 1e9 at the end , then print -1.
  coins[0]=0;                      //minimim no. of coins to achieve 0 is 0.
  
  for(int i=1;i<=sum;i++)     //Calculating Minimum number of coins for every number from 1 to target sum.
  {
    for(int j=0;j<n;j++)    //This loop is taking in account every coin to be "last move".
    {
      if(i>=a[j])         //if last move is greater than target sum,then it will exceed the sum that we dont want.
      { 
        coins[i]=min(coins[i],1+coins[i-a[j]]);    //"1+coins[i-a[j]]" means 1 signifies the count of the last move and coins[i-a[j]] signifies the count of coins before last move.
                                                   //Forex- last move=5 and sum=11 then 1 is for 5 and coins[11-5] is for min. coins which sum to 11-5=6.
      }
    }
  }
  if(coins[sum]==1e9)cout<<-1<<endl;   //if the value is 1e9 which is not possible beacuse biggest input is 1e6 and no. of coins cant be greater that 1e6.thats why i took 1e9 as inital value.So in this case print -1.
  else cout<<coins[sum]<<endl;         //otherwise print the value frm dp array.
}
