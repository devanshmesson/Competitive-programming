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
    mp.clear();
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a;
    cin>>b;

    int diff[n+1];
    int ok=0;
    if(a==b)ok=1;

    int ct=1;
    for(int i=0;i<n;i++)
    {
      if(b[i]==a[i])diff[i]=26;
      if(b[i]>a[i])diff[i]=b[i]-a[i];
      else 
      {
        diff[i]=26-abs(b[i]-a[i]);
      }
      if(ct%2==0)diff[i]=diff[i]*(-1);
      ct++;
    }
    
    int pre[n+1]={0};
    int sum=0;
    for(int i=0;i<n;i++)
    {
     sum+=diff[i];
     pre[i]=sum;
    }
    
    
    vector<pair<int,int>>v;
    for(int i=0;i<q;i++)
    {
      int l,r;
      cin>>l>>r;
      l--,r--;
      v.pb({l,r});
    }
    for(int i=0;i<q;i++)
    {
      int l=v[i].first;
      int r=v[i].second;
      if(ok==1){cout<<"YES"<<endl; continue;}
      if(l==r && a[l]==b[r]){cout<<"YES"<<endl;continue;}

      
      int d;

      if(l==0)d=(pre[r]);
      else d=(pre[r]-pre[l-1]);
      
      if(d==0)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }


  }

}




    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
