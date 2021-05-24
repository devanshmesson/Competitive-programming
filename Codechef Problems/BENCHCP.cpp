#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define endl "\n"
#define pb push_back

int mod=1000000007;
main()
{

  int t;
  cin>>t;
  while(t--)
  {
    int n,w,wr;
    cin>>n>>w>>wr;
    int wt[n+1];
    map<int,int>mp;
    for(int i=0;i<n;i++){cin>>wt[i];mp[wt[i]]++;}

    int req=w-wr;
    if(req<=0){cout<<"YES"<<endl;continue;}
    // if(req%2==1){cout<<"NO"<<endl;continue;}
    int sum=0;
    for(auto x: mp)
    {
      int y=x.second;
      int s=x.first;
      if(y>1)
      {
        if(y%2==1)y--;
        sum+=(s*y);
      }
    }
    if(sum>=req)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


  }
  
  
}
    
