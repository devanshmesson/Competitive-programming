#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long int

main() 
{
   ordered_set s;
   int n,k;
   cin>>n>>k;
   int a[n+1];
   for(int i=0;i<n;i++)cin>>a[i];
   int v=1;
   for(int i=0;i<k;i++)s.insert(a[i]);
   int old=*(s.find_by_order(k%2!=0?k/2:(k/2)-1));
   int ans=0;
   for(int i=0;i<k;i++)ans+=abs(old-a[i]);
   cout<<ans<<" ";
   for(int i=k;i<n;i++)
   {
    v--;
    if(v==0)
    {
      int remove=i-(k);
      s.erase(s.find_by_order(s.order_of_key(a[remove])));
      s.insert(a[i]);
      int neww=*(s.find_by_order(k%2!=0?k/2:(k/2)-1));
      ans+= -abs(old-a[remove]) + abs(neww-a[i]);
      if(k%2==0)ans-=(neww-old);
      cout<<ans<<" ";
      old=neww;
      v=1;
    }
 
   }
  
}
