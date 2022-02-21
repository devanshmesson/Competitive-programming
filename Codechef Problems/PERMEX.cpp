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
    string s;
    cin>>s;

    if(s[0]=='0' || s[1]=='0' || s[n]=='0'){cout<<"No"<<endl; continue;}
    cout<<"Yes"<<endl;
    vector<int>a;
    a.push_back(0);
    a.push_back(1);

    for(int i=2;i<n;i++)
    {
      if(s[i]=='1')a.push_back(i);
      else
      {
        int d=a.back();
        a.pop_back();
        a.push_back(i);
        a.push_back(d);
      }
    }

    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;

  }
  
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
