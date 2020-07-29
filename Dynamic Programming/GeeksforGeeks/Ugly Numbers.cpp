/*
Link-https://www.geeksforgeeks.org/ugly-numbers/
Problem-Find nth number which is only divisible by 2 3 5,let's say this number is ugly.
Time Complexity-O(n)
Approach-Dynamic Programming
        -We are only focussed on numbers which have 2 or 3 or 5 as its factors.
        -Other way of saying is we will multiply only 2 or 3 or 5 with the numbers that are already generated as ugly.
        -if(n==1)ugly number=1 now, for finding for n=2,we will multiply ugly[1] with 2 ,with 3,with 5 and take minimum of these 3 and 
        -that minimum will be our next ugly number.
        -increment the index for the number among 2 or 3 or 5 which was chosen as the minimum number.
        -After incrementing that number will work for that particular index of ugly array.In Other Words,that number will be multiplied with ugly[index].
        -Conclusion is that we take minimum of 3 numbers in every iteration and 2,3,5 are the reason for the 3 three numbers.

*/
#include<bits/stdc++.h>
using namespace std;
main()
{
  int n;
  cin>>n;
  vector<int>ugly(n+1);
  ugly[1]=1;    //1 based indexing
  int a2=1,a3=1,a5=1;
  int min2=ugly[a2]*2;
  int min3=ugly[a3]*3;
  int min5=ugly[a5]*5;

  for(int i=2;i<=n;i++)
  {
    int ans=min(min2,min(min3,min5));
    ugly[i]=ans;
    if(ans==min2)
    {
      a2++;
      min2=ugly[a2]*2;
    }
    if(ans==min3)
    {
      a3++;
      min3=ugly[a3]*3;
    }
    if(ans==min5)
    {
      a5++;
      min5=ugly[a5]*5;
    }
  }
  cout<<ugly[n]<<endl;
}
