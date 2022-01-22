#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif

#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double


signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   set<int>s;
   int suffixmex[n];
   int mex=0;
   //building suffix mex array(precomputation)
   //suffixmex[i] means MEX in range [i,n-1]

   for(int i=n-1;i>=0;i--)
   {
     s.insert(a[i]);
     while(s.count(mex))mex++;
     suffixmex[i]=mex;
   }
   vector<int>ans;
   //Calculate running prefix mex and finding first index of maximum MEX which is stored in suffixmex[i]
   for(int i=0;i<n;)
   { 
      set<int>s;
      int mex=0;
      int j=i;
      ans.pb(suffixmex[i]);
      for(j=i;j<n;j++)
      {
        s.insert(a[j]);
        while(s.count(mex))mex++;
        if(mex==suffixmex[i])break;
      }
      i=j+1;
   }
   cout<<ans.size()<<endl;
   for(auto x:ans)cout<<x<<" ";
   cout<<endl;
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
*/ 
