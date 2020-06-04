/*
Problem-Divide the array into k subarrays,task is to find the maximum sum over all subarrays which is minimum.
       -Same as Painter's Partition Problem (https://www.interviewbit.com/problems/painters-partition-problem/)
       
Time Complexity-O(nLog(sum)) [sum=sum of all array elements]

Appproach- Binary Search
         -Why Binary Search? Notice that the answer will be always be in a range.
         -What Range? if k=1 then ans=sum , if k=size of array then ans=max_element
         -Range is from (max_element to sum )
         -Binary Search between this range
         
Explaination given below is reffering to Painter's Partition Problem to make it easier to understand.
*/
#include<bits/stdc++.h>
 
using namespace std;
#define int long long int
 
 
 
main() 
{
  int n,k,sum=0,mx=INT_MIN;
  cin>>n>>k;
  int a[n+1];
  for(int i=0;i<n;i++){cin>>a[i]; sum+=a[i];mx=max(mx,a[i]);}
  int low=mx,high=sum;
 
  auto solve=[&](int mid)   //Lambda function to count how many painters are required in the time given.If time is sufficient then,we will see if more lesser time is sufficient or not because we have to minimize the time.
  {
    int sum=0,cnt=1;                  //Initializing no. of subarrays by 1 becuase max req. time to paint the board will not be more than sum of all elements.
    for(int i=0;i<n;i++)         
    {
      if(a[i]>mid)return 0;           //if a[i] > req.time to paint the board,then this element cannot come in any subarray becuase sum will exceed.
      sum+=a[i];
      if(sum>mid)                     
      {
        cnt++;                         //It means that the particulat subarray'sum exceeded the req. time.so next painter will proceed painting.
        sum=a[i];
      }
    }
    if(cnt<=k)return 1;
    else return 0;
  };
  int ans=0;
  while(low<=high)                //Binary Search
  {
    int mid=(low+high)/2;
    if(solve(mid))
    {
      ans=mid;
      high=mid-1;
    }
    else
    {
      low=mid+1;
    }
 
  }
  cout<<ans<<endl; 
}
