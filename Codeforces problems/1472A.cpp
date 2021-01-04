#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"
int main()
{
    io
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
       int w,h,n;
       cin>>w>>h>>n;
       if(n==1){cout<<"YES"<<endl;continue;}
       int ans=1;
       while(1)
       {
          int ok=0;
          if(w%2==h%2 && w%2==0)
          {
            if(w>=h && w>1)
            {
              ok=1;
              w/=2;
              ans*=2;
            }
            else if(w<h && h>1)
            {
              ok=1;
              h/=2;
              ans*=2;
            }
          }
          else if(w%2!=h%2)
          {
             if(w%2==0 && w>1)
             {
               ok=1;
               w/=2;
               ans*=2;
             }
             else if(h%2==0 && h>1)
             {
               ok=1;
               h/=2;
               ans*=2;
             }
          }
          if(ok==0)break;
       }
       if(ans>=n)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
}
