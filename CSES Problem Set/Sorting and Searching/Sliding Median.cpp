/* 
Problem-To print median of every window of size-"x" in the given array
Time Complexity-O(nlog(x))
Approach-Used Policy Based Data Structure
        -Add first "x" elements of the array, print median in O(Log k) time.
        -Erase the first element of the window (according to array) and add current element in the iteration,then print the median.
        -Used (less_equal)parameter in pbds to allow duplicates to the data structure.
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
main() 
{
   ordered_set s;
   int n,x;
   cin>>n>>x;
   int a[n+1];
   for(int i=0;i<n;i++)cin>>a[i];
   int v=x;
   for(int i=0;i<n;i++)
   {
     s.insert(a[i]);
     v--;
     if(v==0)
     {
       cout<<*(s.find_by_order(x%2!=0?x/2:(x/2)-1))<<" ";
       int ind=i-(x-1);
       s.erase(s.find_by_order(s.order_of_key(a[ind])));
       v=1;
     }
   }

}
  


  
