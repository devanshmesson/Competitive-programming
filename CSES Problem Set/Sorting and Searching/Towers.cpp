/*
Question -Find Upper bound effiecintly using multiset
Solved - O(nlogn) Time Complexity
Approach-Used Upper Bound in multiset - AC  multiset is sorted(thats why AC)
        -Used Upper Bound in Vector -TLE  (Complexity - O(n^2) or O((nlogn)^2)
*/
#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define int long long int
#define endl "\n"
main() 
{ 
  io
 int n,a;
 cin>>n;
 multiset<int>s;
 for(int i=0;i<n;i++)
 {
   cin>>a;
   auto it=s.upper_bound(a);
   if(it==s.end())s.insert(a);
   else
   {
    s.erase(it);
    s.insert(a);
   }
 }
 cout<<s.size();
}
