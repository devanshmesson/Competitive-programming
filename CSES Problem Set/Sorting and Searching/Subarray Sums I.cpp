/*Problem- Count subarrays having sum equal to a given value(x)
  Time Complexity-O(n)
  Approach-Made a prefix array.
          -Pref[High]-Pref[Low-1]=x
          -High will be all elements of array(by traversal)
          -To Calculate Low where condition satisfies => pref[low]=pref[High]-x
          -Put prefix sum values till the "High"th index in a hash table(unordered map) and check if(pref[High]-x) is there in hash table or not.
include<bits/stdc++.h>
using namespace std;
main() 
{
  io
  int n,x;
  cin>>n>>x;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  map<int,int>hash;
  hash[0]++;
  int ans=0,pref=0;
  for(int i=0;i<n;i++)
  {
    pref+=a[i];
    int need=pref-x;
    ans+=hash[need];
    hash[pref]++;
  }
  cout<<ans<<endl;
}
