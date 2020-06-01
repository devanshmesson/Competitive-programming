/*Problem - Find 4 elements in an array which sum to a given value(x)
  Time Complexity-O(n^2 Log (n^2)) - vector is of size n^2 so sorting it takes O(n^2 Log (n^2))
  (Reason for size of vector is- No. of pairs in an array is (n*(n-1)/2) )
  Approach-Store sum of all pairs with their two indexes in a vector of tuple.
          -Sort the vector of tuple
          -Now the problem boils down to find two elements which sums to a given value(x) -> This can be done in a loop
  Other Approaches- Used Unordered_map - TLE worst case is O(n)
                  - Used map -AC but approach is wrong because if various pairs have same sum then unordered_map will
                    store only one pair among all those pairs ,but multimap will store all pairs which has same sum.
                  - So i Used Multimap -AC but complexity is not much good.
*/

#include<bits/stdc++.h>
using namespace std;
main() 
{
  //freopen
  io
  int n,x;
  cin>>n>>x;
  int a[n+1],sum=0;
  for(int i=0;i<n;i++)cin>>a[i];
  vector<tuple<int,int,int>>store;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      sum=a[i]+a[j];
      store.push_back({sum,i,j});
    }
  }
  sort(store.begin(),store.end());
  int size=n*(n-1)/2;
  int low=0,high=size-1;
  bool yes=0;
  while(low<high)
  {
    
    if((get<0>(store[low])+get<0>(store[high]))==x)
    {
      if(get<1>(store[low])!=get<1>(store[high]) && get<1>(store[low])!=get<2>(store[high])  &&  get<2>(store[low])!=get<1>(store[high]) && get<2>(store[low])!=get<2>(store[high]) )
      {
        yes=1;
        cout<<get<1>(store[low])+1<<" "<<get<2>(store[low])+1<<" "<<get<1>(store[high])+1<<" "<<get<2>(store[high])+1<<endl;
        break;
      }
      else low++;
    }
    else if((get<0>(store[low])+get<0>(store[high]))>x)high--;
    else low++;
  }
  if(!yes)cout<<"IMPOSSIBLE"<<endl;
} 
