/*Problem- Divide the sorted array into k subarrays such that sum of (max element-min element) of every subarray is minimal
  Time Complexity-O(nLogn)
  Approach-we will consider consecutive differences and put it in vector and sort it.
          -Idea is to not put the elements in the same set whose difference is maximum.
          -This can be achieved by not including maximum k-1 differences in the answer.
          -Why k-1? because k-1 differences means putting k-1 elements in different sets to mnimize the answer.
          -For ex 
           5 3
           1 3 3 4 5   =>we will put 1 & 3  and  3 & 4 in different sets to minimize the answer.
*/
include<bits/stdc++.h>
using namespace std;
main() 
{
  int n,k;
  cin>>n>>k;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  vector<int>diff;
  for(int i=1;i<n;i++)diff.push_back(abs(a[i]-a[i-1]));
  sort(diff.begin(),diff.end());
  int ans=0;
  for(int i=0;i<n-k;i++)
  {
   ans+=diff[i];

  }
  cout<<ans<<endl;
}
