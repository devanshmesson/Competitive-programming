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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int a[n];
    int consistent=0,flag=0;
    int okay=1;
    for(int i=0;i<n;i++)
    {
      int no=(int)s[i]-48;
      if(no!=0)a[i]=10-no;
      else {a[i]=no;}
    }
    int ok=1,upd=0;
    int second=0,comp=a[0];
    do
    {
     ok=1;
     flag=0;
     int minus;
     if(second>=1)comp=10;
     if(k>=comp && upd<n)
     {
      for(int i=upd;i<n-1;i++)
      {
       if(a[i]>=a[i+1] && flag==0)consistent++;
       if(a[i]<a[i+1] && flag==0){minus=a[i];flag=1;break;}
      }
      consistent++;
     }
     else {cout<<consistent<<endl;ok=0;break;}
     k-=comp;
     upd=(consistent);
     second++;
    }while(k>=10); 
    if(ok==1)cout<<consistent<<endl;  
  } 
    }
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
    */    
