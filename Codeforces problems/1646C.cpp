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

  int x=1000000000000;
  int t;
  cin>>t;

  int d=1,res=1;
  vector<int>v;
  while(1)
  {
    res*=d;
    if(res>x)break;
    v.push_back(res);
    d++;
  }
  v.erase(v.begin());
  v.erase(v.begin());

  
  while(t--)
  {
    int n;
    cin>>n;
    
    int till=(1<<12);
    int sum=0;
    int mini=INT_MAX;
    for(int number=0;number<=till;number++)
    {
      bitset<12>a(number);
      sum=0;
      int cnt=0;
      for(int bit=0;bit<a.size();bit++)
      {
        if(a[bit]==1){sum+=v[bit];cnt++;}
      }
      if(sum>n)continue;
      int left=n-sum;
      bitset<50>b(left);
      mini=min(mini,(int)b.count()+cnt);
    }
    cout<<mini<<endl;
  }

    
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
