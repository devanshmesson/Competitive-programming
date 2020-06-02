/*Problem- Count Subarrays which are divisible by size of array(n)
  Time Compelxity-O(n)
  Approach-Solved through Prefix sum
          -(Pref[R]-pref[L])%n=0 => pref[R]%n-pref[L]%n=0 =>pref[R]%n=pref[L]%n
          -Put value of pref[R]%n in hash table till the Rth index and check whether if value of pref[R]%n is present in array or not.
       Imp-Negative Modulo is if(x<0)((x%mod)+mod)%mod
*/
include<bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define freopen //comment
#endif
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define int long long int
 

main() 
{
  int n;
  cin>>n;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  unordered_map<int,int>hash;
  hash[0]++;
  int ans=0,pref=0,need;
  for(int i=0;i<n;i++)
  {
    pref+=a[i];
    if(pref<0)need=((pref%n)+n)%n;
    else need=pref%n;
    ans+=hash[need];
    hash[need]++;
  }
  cout<<ans<<endl;
}

  


  
