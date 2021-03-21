#include<bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  vector<int>ps;
  for(int i=1;i*i<=1000000;i++)
  {
     ps.push_back(i*i);
  }

  while(t--)
  {
    int i=0,ans,flag=0;
    while(1)
    {
      cout<<ps[i]<<endl;
      cin>>ans;
      fflush(stdout);

      if(ans==0)
      {
        i++;
      }
      else if(ans==-1){flag=1;break;}
      else if(ans==1){flag=-1;break;}
    }
    fflush(stdout);
    if(flag==1)break;
  }
    
}
