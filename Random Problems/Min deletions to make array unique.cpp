// Minimum cost of deletions. You have two arrays. First contains the letters a-z and the second contains the integer cost of deleting that element. 
//Return the total cost of deletion for an array that contains repeating elements in order to make its elements unique.
#include<bits/stdc++.h>
using namespace std;

signed main()
{
  freopen
  ios
  int b[5]={4,5,6,7,8};
  char a[6]={'a','b','a','a','c'};
  int hash[26]={0};
  int n=6;
  for(int i=0;i<n;i++)
  {
    hash[a[i]-'a']++;
  }
  int ans=0;
  for(int i=0;i<5;i++)
  {
    if(hash[i]==0)continue;
    ans+=(hash[i]-1)*b[i];
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
    
    
