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
    if(n==2){cout<<"NO"<<endl;continue;}
    cout<<"YES"<<endl;
    int temp=n;
    vector<int>v;  
   
    if((n&1)==0)
    {
      deque<int>d;
      d.push_back(2);
      d.push_back(1);
      d.push_back(4);
      d.push_back(3);
      n-=4;
      n/=2;
      int start=5;
      for(int i=0;i<n;i++){d.push_front(start);start+=2;}
      start=6;
      for(int i=0;i<n;i++){d.push_back(start);start+=2;}
      for(int i=0;i<d.size();i++)cout<<d[i]<<" ";
    }
    else
    {
      v.push_back(1);
      n-=3;
      n/=2;
      int till=3+n;
      for(int i=till;i>=4;i--)v.pb(i);
      v.pb(3);
      for(int i=till+1;i<=till+n;i++)v.pb(i);
      v.pb(2);
      for(auto x:v)cout<<x<<" ";
    }
    cout<<endl;
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
*/ 
