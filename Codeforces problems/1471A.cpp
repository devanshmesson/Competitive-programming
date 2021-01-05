#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"
int main()
{
    io
    #define int long long int
    /*
     Logic of the problem: 
     ceil(a+b/x) <= ceil(a/x) + ceil(b/x)
    */
    int t;
    cin>>t;
    while(t--)
    {
      int n,x,a;
      cin>>n>>x;
      int sum=0,s=0;
      for(int i=0;i<n;i++)
      {
        cin>>a;
        sum+=a;
        if(a%x!=0)
        {
          s+=a/x;
          s++;
        }
        else s+=a/x;
      }
      int ans=0;
      if(sum%x!=0){ans+=sum/x;ans++;}
      else {ans=sum/x;}
      cout<<ans<<" "<<s<<endl;
    }
  }
