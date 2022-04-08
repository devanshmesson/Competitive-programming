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
    map<int,int>mp;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
      {
        cin>>a[i]; 
        mp[a[i]]++;
        maxi=max(maxi,mp[a[i]]);
      }
      if(maxi==n){cout<<0<<endl; continue;}
    

    int lef=n-maxi;
    if(lef<=maxi)
    {
      cout<<1+lef<<endl;
      continue;
    }
    int swap=0;
    int clone=0;
    int equal=maxi;
    int cnt=0;
    while(1)
    {
      clone++;
      swap=equal;
      cnt+=swap;
      equal=2*swap;
      int left=n-equal;
      if(left==0)break;
      // cout<<clone<<" "<<swap<<" "<<equal<<endl;
      if(left<=equal)
      {
        // cout<<"yes:"<<clone<<" "<<swap<<endl;
        // cout<<"equal:"<<equal<<endl;

        clone++;
        swap=left;
        cnt+=swap;
        break;
      }
    }

    cout<<cnt+clone<<endl;



  }
 
}


/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
