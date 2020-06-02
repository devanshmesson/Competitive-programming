/*Problem- Count subarrays having sum equal to a given value(x)
  Time Complexity-O(n)
  Approach-Made a prefix array.
          -Pref[High]-Pref[Low-1]=x
          -High will be all elements of array(by traversal)
          -To Calculate Low where condition satisfies => pref[low]=pref[High]-x
          -Put all prefix sum values in a hash table(unordered map) and check if(pref[High]-x) is there in hash table or not.
include<bits/stdc++.h>
using namespace std;
main() 
{
  int n,x;
  cin>>n>>x;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  int pref[n+1]={0};
  unordered_map<int,int>hash;
  hash[0]++;
  for(int i=0;i<n;i++)
  {
    pref[i]=a[i]+(i==0?0:pref[i-1]);
    hash[pref[i]]++;
  }
  int ans=0;
  for(int i=0;i<n;i++)
  {
    int need=pref[i]-x;
    ans+=hash[need];
  }
  cout<<ans<<endl;
}
