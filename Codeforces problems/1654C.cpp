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
    int sum=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];mp[a[i]]++;}
    if(n==1){cout<<"YES"<<endl; continue;}
    queue<pair<int,int>>q;
    q.push({1,sum});
    int comp=0;
    int cut=0;
    while(cut<n-1)
    {
      if(q.empty())break;
      int n=q.front().second;
      int lev=q.front().first;
      q.pop();
      cut++;

      int d1,d2;
      if(n%2==0)
      {
        d2=d1=n/2;
      }
      else
      {
        d1=n/2;
        d2=d1+1;
      }
      int flag=0, choose=-1;
      if(mp[d1]>0){comp++; mp[d1]--; flag++; choose=1;}
      if(mp[d2]>0){comp++; mp[d2]--; flag++; choose=2;}
      if(flag==2)continue;

      if(choose==1)q.push({lev+1,d2});
      else if(choose==2)q.push({lev+1,d1});
      else 
      {
        q.push({lev+1,d1});
        q.push({lev+1,d2});
      }
    }

    if(comp==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
    
    
