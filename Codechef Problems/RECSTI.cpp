// taskkill /IM "a.exe" /F
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


int help(int n)
{
  int temp=n;
    int sum=0;
    while(temp>0)
    {
      int k=temp%10;
      temp/=10;
      sum+=k;
    }
    return sum;
}
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
    int a[n+1];
    int ans=0;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    priority_queue<int>pq;
    for(int i=0;i<n;i++)
      {
        mp[a[i]]++;
      }

    for(auto x: mp)
      {
        if(x.second%2==1)
        {
          ans++;
          pq.push(x.second+1);
        }
        else pq.push(x.second);
      }


    while(pq.size()>1)
    {
      int big=pq.top();
      pq.pop();
      int small=pq.top();
      pq.pop();
      if((big-small)>0)pq.push(big-small);
    }
    if(pq.size()==1)
    {
      int left=pq.top();
      if(left%4==0);
      else 
      {
        int y=left/4;
        y++;
        int target=y*4;
        ans+=(target-left);
      }
    }
    
    cout<<ans<<endl;

    

  }
}


/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
