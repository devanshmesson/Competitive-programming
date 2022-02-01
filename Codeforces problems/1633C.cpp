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
   int hc,dc,hm,dm,k,w,a;
   cin>>hc>>dc>>hm>>dm>>k>>w>>a;
   
   int x=(hm+dc-1)/(dc);
   int y=(hc+dm-1)/dm;
   if(x<=y){cout<<"YES"<<endl;continue;}

   int flag=0;
   for(int i=0;i<=k;i++)
   {
     int m1,m2;
     m1=i*w;
     m2=(k-i)*a;
     
     x=(hm+dc+m1-1)/(dc+m1);
     y=(hc+m2+dm-1)/dm;

     if(x<=y){flag=1;break;}
   }

   if(flag==1)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;   
  }
  

}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
    */
