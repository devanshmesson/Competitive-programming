/*
Question - longest substring after adding each element between 0 and given number.This element is a barrier in the segment [0,given number]
Solved - O(nLogn) Time-Complexity
Approach-Focus is on the segment which will be affected after adding an element.That Segment will be found by calculating 
         upper bound and lower bound on the set which is containing the previously input numbers.Multiset is used to 
         contain all possible paths and deleting the segment which will be affected by adding the input.
         Add the two parts of affected segment back in the multiset and maximum element in multiset is our answer for particular input.
*/

#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define int long long int
#define endl "\n"
main() 
{ 
 int x,n,a;
 cin>>x>>n;
 set<int>s;
 multiset<int>m;
 s.insert(0);
 s.insert(x);
 for(int i=0;i<n;i++)
 {
  cin>>a;
  auto l=s.lower_bound(a); // doing lower bound upper bound for bounds of the input
  auto r=s.upper_bound(a);
  if(l==r)--l;
  auto del=m.find(*r-*l);
  if(del!=m.end())m.erase(del);
  m.insert(a-*l);  //added left segment
  m.insert(*r-a);  //added right segment
  s.insert(a);     //For Next input
  cout<<*--m.end()<<" "; /*Maximum element in multiset will be the longest path
                           without traffic lights*/
 }
}
