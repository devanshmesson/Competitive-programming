#include<bits/stdc++.h>
using namespace std;
main()
{ 
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    int  cnt=0;
    int m1=INT_MAX,m2=INT_MAX;

    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      m1=min(m1,a[i]);
    }
    for(int i=0;i<n;i++)
    {
      cin>>b[i];
      m2=min(m2,b[i]);
    }
    for(int i=0;i<n;i++)
    {
      if(a[i]>m1 && b[i]>m2)
      {
        int d=min(abs(a[i]-m1),abs(b[i]-m2));
        a[i]-=d;
        b[i]-=d;
        cnt+=d;
      }
      if(a[i]>m1 && b[i]==m2)
      {
       cnt+=(abs(a[i]-m1));
       a[i]-=abs(a[i]-m1);
      }
      if(b[i]>m2 && a[i]==m1)
      {
         cnt+=(abs(b[i]-m2));
         b[i]-=abs(a[i]-m1);
      }
    }
   cout<<cnt<<endl;
  }
}
