#include<bits/stdc++.h>
using namespace std;
int main() 
{
   #define int long long int 
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     cin>>n;
     if(n==1){cout<<0<<endl;continue;}
     if(n%3!=0){cout<<-1<<endl;continue;}
     bool flag=1;
     int ans=0,ok=0;
     while(n>1)
     {
      if(n%6==0)
      {
        n/=6;
        ans++;
        if(n==1){ok=1;break;}
      }
      else if(n%6!=0 && n%3==0)
       {
          n*=2;
          ans++;
          if(n==1){ok=1;break;}
       }
      else if(n%3!=0){flag=0;break;}
     }
     if(ok)cout<<ans<<endl;
     else cout<<-1<<endl;
   }
}
