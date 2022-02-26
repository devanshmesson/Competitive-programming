// https://www.geeksforgeeks.org/maximum-even-sum-subsequence-of-length-k/
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
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
  int a[] = {5, 5, 2, 4, 3};
  int k=3;
  int n=5;
  vector<int>odd,even;
  for(int i=0;i<n;i++)
  {
    if(a[i]%2==0)even.push_back(a[i]);
    else odd.push_back(a[i]);
  }

  sort(even.begin(),even.end(),greater<int>());
  sort(odd.begin(),odd.end(),greater<int>());
  int os=odd.size(),es=even.size();
  int i=0,j=0;

  int ans=0;
  int flag=0;
  while(k>0)
  {
    if(k%2==1)
    {
      if(es==0){flag=1;break;}
      else 
      {
        ans+=even[i];
        i++;
        k--;
      }
    }
    else if(k%2==0)
    {
      if(i+1<es && j+1<os)
      {
        int s1=even[i]+even[i+1];
        int s2=odd[j]+odd[j+1];
        if(s1>s2){ans+=s1;i+=2;}
        else {ans+=s2;j+=2;}
        k-=2;

      }
      else if(i+1<es)
      {
        ans+=even[i]+even[i+1];
        k-=2;
        i+=2;
      }
      else if(j+1<os)
      {
        ans+=odd[j]+odd[j+1];
        k-=2;
        j+=2;
      }
      else {flag=1;break;}
    }
  }
  if(flag==1)cout<<-1<<endl;
  else cout<<ans<<endl;

}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
