/*
Problem-Given "n" coins with some values.We need to find number of distinct ways to achieve sum "x".
Time Complexity-O(n*sum)
Approach-Focus on last move which will be among the given array.
        -Now Our Subproblem gets reduced to finding number of ways to achieve sum "x-lastmove".
        
        For Example:
        n=3 sum=9
input array-2 3 5
        If last move is 2 then we have achieved 7
        if last move is 3 then we have achieved 6
        if last move is 5 then we have achieved 4.
        
        Now we have to find number of ways to achieve sum 7,6,4.
        
        In General(referring above example),
        Let:
        A-Number of ways to achieve sum "x-2"
        B-Number of ways to achieve sum "x-3"
        C-Number of ways to achieve sum "x-5"
        X-Number of ways to complete particular last move(2,3,5) =1
        
        Final Answer-A*X + B*X + C*X
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  int n,sum,mod=1e9+7;
  cin>>n>>sum;
  vector<int>a(n+1); //Mandatory to include size if you wish to use easy method of inputting in line "33".
  for(auto &v:a)cin>>v;  //Easy way to input in vector if and if size is mentioned .
  vector<int>ways(1000001,0);   //DP array for storing no. of ways for achieving some sum x.  
  ways[0]=1;   //Only 1 way is there to be on 0th place.
  for(int i=1;i<=sum;i++)  //instead of doing recursively, doing iteratively and calculating all values till target_sum staring from 1.
  {
    for(int lastmove=0;lastmove<n;lastmove++)  // Taking in account all coins to be lastmove and adding their contribution.
    {
      if(i>=a[lastmove])  //Checking the condition if the last move is not exceeding the required sum "i".
        {   
          (ways[i]+=ways[i-a[lastmove]])%=mod;   //Cool way to computing mod.Learnt through icecuber's editorial on Codeforces.
        }
    }
  }
  cout<<ways[sum]<<endl; //Printing the final answer.i.e no. of all possible ways to achieve sum "x" with given some values.
}
