/*Problem-Minimum time required to read all books by two persons(they cannot read book at same time)
  Time Complexity-O(n)
  Approach-if maximum time >= sum of all other times then total time reqd will be 2*(maximum time) 
  (if we dont do this then j have to wait for book that k is reading currently and j doesn't have any other book so it will cause delay)
          -if maximum time < sum of all other times then total time reqd will be sum of all times
*/
 #include<bits/stdc++.h>
using namespace std;
#define int long long int
main() 
{
  int n,sum=0,mx=0,x;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    sum+=x;
    mx=max(mx,x);
  }
  if(mx>=(sum-mx))cout<<2*mx<<endl;
  else cout<<sum<<endl;
}
 
