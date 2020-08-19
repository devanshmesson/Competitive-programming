#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
   string s;
   cin>>s;
   int n=s.size();
   int x,y,a,b;
   cin>>x>>y;
   int q,r=0,l=0,u=0,d=0;
   cin>>q;
   for(int j=0;j<n;j++)
     {
      if(s[j]=='U')u++;
      if(s[j]=='L')l++;
      if(s[j]=='R')r++;
      if(s[j]=='D')d++;
     }
   for(int i=0;i<q;i++)
   {
     cin>>a>>b;
     if(a==x && b==y)
     {
      cout<<"YES ";
      cout<<0<<endl;
      continue;
     } 
    int dif1,dif2;
    dif1=abs(a-x);
    dif2=abs(b-y);
    char s1,s2;
    int yes=0;

     if(a>x)
     {
        if(r>=dif1)yes++;
     }
     if(a<x)
     {
       if(l>=dif1)yes++;
     }
     if(b>y)
     {
        if(u>=dif2)yes++;
     }
     if(b<y) 
     {
       if(d>=dif2)yes++;
     }

     if(yes==2 && dif1>0 && dif2>0)
     {
      cout<<"YES ";
      cout<<dif1+dif2<<endl;
     }
     else if(yes==1)
     {
       if(dif1>0 && dif2==0)
        {
          cout<<"YES ";
          cout<<dif1+dif2<<endl;
        }
        else if(dif2>0 && dif1==0)
        {
          cout<<"YES ";
          cout<<dif1+dif2<<endl;
        }
        else if(dif1>0 && dif2>0)
        {
            cout<<"NO"<<endl;
        }
     }
     else cout<<"NO"<<endl;
   }
 }
}
