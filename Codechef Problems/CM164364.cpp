#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define pb push_back
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x;
    cin>>n>>x;
    int a[n+1];
    map<int,int>mp;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        mp[a[i]]++;
      }
      int sum=0,flag=0;
  
      for(auto y:mp)
      {
        if(sum>=x){flag=1;break;}
        if(y.second>1)
        {
         sum+=y.second-1;
        }
      }

      if(sum>=x){flag=1;}

      if(flag==1)
      {
        cout<<mp.size()<<endl;
        continue;
      }

      int mps=mp.size();
      int rem=x-sum;
      cout<<mps-rem<<endl;
  }
}
