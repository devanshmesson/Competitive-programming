// taskkill /IM "a.exe" /F
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

bool sortbysec(const pair<int,int>a, const pair<int,int>b)
{
  if(a.first==b.first && a.second>b.second)return a<b;
  return a<b;
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
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    stack<pair<int,int>>s;//max,min
    s.push({a[0],a[0]});
    for(int i=1;i<n;i++)
    {
      s.push({a[i],a[i]});
      while(s.size()>=2)
      {   
        int curmax=s.top().first;
        int curmin=s.top().second;
        s.pop();
        int prevmax=s.top().first;
        int prevmin=s.top().second;
        s.pop();
        if(prevmax>curmin)
        {
          curmax=max(curmax,prevmax);
          curmin=min(curmin,prevmin);
          s.push({curmax,curmin});
        }
        else 
        {
          s.push({prevmax,prevmin});
          s.push({curmax,curmin});
          break;
        }
      }
    }
    cout<<s.size()<<endl;
  }

}
