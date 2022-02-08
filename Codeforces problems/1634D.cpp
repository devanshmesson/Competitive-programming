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
    int a=1,b=2;
    vector<pair<int,int>>v(5);
    int save=0;
    for(int i=3;i<=n;i+=2)
    {
      int c=i,d=i+1;
      if(d>n)d=save;

      cout<<"? "<<b<<" "<<c<<" "<<d<<endl;
      cout.flush();
      cin>>v[1].first;
      v[1].second=a;
      cout<<"? "<<a<<" "<<c<<" "<<d<<endl;
      cout.flush();
      cin>>v[2].first;
      v[2].second=b;
      cout<<"? "<<a<<" "<<b<<" "<<d<<endl;
      cout.flush();
      cin>>v[3].first;
      v[3].second=c;
      cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
      cout.flush();
      cin>>v[4].first;
      v[4].second=d;
      sort(v.begin()+1,v.end());
      a=v[1].second;
      b=v[2].second;
      save=v[3].second;
    }
    cout<<"! "<<a<<" "<<b<<endl;
    cout.flush();
  }
}
    /*1.Never overkill a problem.
      2.think of test ca
      ses to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
