#include<bits/stdc++.h>
using namespace std;
int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int s,n;
    cin>>s>>n;
    if(s==1){cout<<1<<endl;continue;}
    if(s<=n)
    {
      if(s%2!=0)cout<<2<<endl;
      else cout<<1<<endl;
    }
    else 
    {
      int ans=s/n;
      if(s%n!=0)
      {
        int b=s%n;
        if(b==1)ans+=1;
        else if(b%2!=0)ans+=2;
        else ans+=1;
      }
      cout<<ans<<endl;
    }
   }
  }
