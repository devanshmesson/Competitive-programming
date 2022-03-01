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

const int mod=998244353;

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
    int a[n],idol[n],temp[n];
    for(int i=0;i<n;i++){cin>>a[i];idol[i]=a[i];temp[i]=a[i];}
    string s;
    cin>>s;
    if(is_sorted(a,a+n)){cout<<0<<endl;continue;}
    if(s[0]!=s[n-1]){cout<<1<<endl;continue;}
    
    int p=-1;
    for(int i=1;i<n;i++)
    {
      if(s[0]!=s[i])p=i;
    }
    if(p==-1){cout<<"-1"<<endl;continue;}
    sort(temp,temp+p+1);
    if(is_sorted(temp,temp+n)){cout<<1<<endl;continue;}

    for(int i=0;i<n;i++)temp[i]=a[i];

    p=-1;
    for(int i=n-2;i>=0;i--)
    {
      if(s[n-1]!=s[i])p=i;
    }
    if(p==-1){cout<<"-1"<<endl;continue;}

    sort(temp+p,temp+n);
    if(is_sorted(temp,temp+n)){cout<<1<<endl;continue;}

    cout<<2<<endl;





    

  }
 
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
