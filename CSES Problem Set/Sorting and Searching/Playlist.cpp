/*
Question - Longest substring with unique characters
Solved - O(n) Time-Complexity
Approach-Stored index of the last occurrence of every element and 
         Whenever there comes a repeted number then the starting index of 
         next window is changed to lastindex[repeted num]+1
*/
#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define int long long int

main() 
{ 
  io
 int n;
 cin>>n;
 map<int,int>lastind;
 int a[n+1];
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 int i=1,ans=0;
 for(int j=1;j<=n;j++)
 {
  i=max(i,lastind[a[j]]+1);
  ans=max(ans,j-i+1);
  lastind[a[j]]=j;
 }

 cout<<ans<<endl;
 
}
