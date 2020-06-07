#include<bits/stdc++.h>
using namespace std;

main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int n,a,b,flag=0;
    cin>>n;
    int upd=-1;
    for(int i=0;i<n;i++)
    {
      cin>>a;
      if(upd>a)flag=1;
      upd=a;
   }
    bool yes=0,ok=0;
    for(int i=0;i<n;i++)
    {
      cin>>a;
      if(a==0)ok=1;
      else if(a==1){yes=1;}
    }
    if(!flag){cout<<"Yes"<<endl;continue;}
    if(yes && ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
   }
}
