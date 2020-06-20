#include<bits/stdc++.h>
using namespace std;
#define mk make_pair
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m=INT_MIN,a;
    cin>>n;
    vector<int>e,o;
    int se=0,so=0;
    for(int i=0;i<(2*n);i++)
    {
      cin>>a;
      e.pb(a);
    }
    int cnt=0,flag=1,nxt=0;
    map<int,int>mp;
    for(int i=0;i<(2*n);i++)
    {
      flag=1;
      for(int j=i+1;j<(2*n);j++)
      {
          if(cnt==(n-1)){flag=0;break;}
          if((e[i]+e[j])%2==0 && mp[i]==0 && mp[j]==0)
          {
            cnt++;
            mp[i]++;mp[j]++;
            cout<<i+1<<" "<<j+1<<endl;
            nxt=1;
            break;
          }
      }
      if(flag==0)break;
    }
  }
 } 
