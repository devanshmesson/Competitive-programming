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

// const int mod=1000000009;

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
    vector<string>v(n+1);
    string a;
    int flag=0,ok=0;
    map<string,int>mp;
    int index=1;
    for(int i=1;i<=n;i++)
    {
      cin>>a;
      mp[a]++;
      ok=0;
      if(mp[a]==1)v[index++]=a;
      if(a.size()==1)flag=1;
      for(int i=0,j=a.size()-1;i<j;i++,j--)
      {
        if(a[i]!=a[j])ok=1;
      }
      if(ok==0)flag=1;
    }
    if(flag==1){cout<<"YES"<<endl;continue;}
    n=index-1;
    vector<string>vr;
    mp.clear();
    for(int i=1;i<=n;i++)
    {
      mp[v[i]]++;
      string rev=v[i];
      reverse(rev.begin(),rev.end());
      vr.pb(rev);
    }
    for(int i=0;i<n;i++)
    {
      mp[vr[i]]++;
      if(mp[vr[i]]>1){flag=1;break;}
    }
    if(flag==1){cout<<"YES"<<endl;continue;}

    mp.clear();
    map<string,int>mp1;
    for(int i=1;i<=n;i++)
    {
      string rev;
      if(v[i].size()==2)
      {
        mp[v[i]]=i;
        rev.pb(v[i][1]);
        rev.pb(v[i][0]);
        mp1[rev]=i;
      }
    }
    for(int i=1;i<=n;i++)
    {
      string rev;
      string rev1;
      if(v[i].size()==3)
      {
         rev.pb(v[i][2]);
         rev.pb(v[i][1]);
         if(i>mp[rev] && mp[rev]>0){flag=1;break;}

         rev1.pb(v[i][0]);
         rev1.pb(v[i][1]);
         if(i<mp1[rev1] && mp1[rev1]>0){flag=1;break;}
      }
    }
    if(flag==1){cout<<"YES"<<endl;continue;} 
    cout<<"NO"<<endl;
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
*/  
