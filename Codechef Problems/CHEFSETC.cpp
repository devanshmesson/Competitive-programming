/*
Problem-Given an array of 4 numbers,if sum of any subset of the array is 0 print "yes" else "No"
Time Complexity-O(n*(2^n))n=4
Approach-Generate all possible subsets by bitmasking.
        -Just run a loop(i) till (2^4)-1 and a nested loop(j) till 4.Check if (2^j)&i==1 it means that particular bit is set.
        -Each sub-set can be represented by a 4-bit number.
        -And sum of  those elements who have corressponding index as set in the binary representation.
*/
#include<bits/stdc++.h>
using namespace std;

main()
{ 
  int t;
  cin>>t;
  while(t--)
  {
    int a,ans=0;
    vector<int>x;
    for(int i=0;i<4;i++){cin>>a;x.pb(a);}

    for(int i=0;i<(1<<4);i++)
    {
      int sum=0,ok=0;
      for(int j=0;j<4;j++)
      {
        if((1<<j)&i)
        {
          ok=1;
          sum+=x[j];
        }
      }
      if(sum==0 && ok){ans=1;}
    }
    if(ans)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
  }
}
