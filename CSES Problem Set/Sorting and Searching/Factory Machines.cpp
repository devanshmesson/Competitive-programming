/*
Question -Minimum time to make t products by n machines(running simultaneously)Given: time for each machine to make one product.
Solved - O(nlog(10^18)) Time Complexity
Approach-set upper bound as 1e18 because the worst case will be no. of req items=1e9 and no. of machines=1 so max.answer will not be more than 1e18.
        -Apply Binary search after that 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  int n,t;
  cin>>n>>t;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];

  int low=0,high=1e18,mid;      
  
  auto solve=[&](int mid)      //lambda function to calculate if in "mid" time making of required no. of items possible or not.
  {
    int item=0;
    for(int i=0;i<n;i++){item+=mid/a[i];if(item>=t)return 1;}  //took care of overflow here.I got overflow issue if this "if" condition is out of loop.It will cause overflow.
    return 0;                                                      
  };
  
  while(low+1<high)                    //Why low+1? because if it isn't low+1 then loop will go infinite as low will be high-1 ultimately so lo and high will never change after that.
  {
    mid=(low+high)/2;
    if(solve(mid)){high=mid;}     //Binary search for finding the solution.
    else {low=mid;}
  }

  cout<<high<<endl;                  //high will be answer
  }
