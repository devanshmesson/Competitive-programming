#include<bits/stdc++.h>
using namespace std;
#define int long long int

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin);freopen("out.txt","w",stdout);
#else
#define freopen //commentb
#endif


signed main()
{
  freopen
  int  t;
  cin>>t;
  while(t--)
  {
    int n,k,bit;
    cin>>n;
    vector<int>v[n];
    unordered_map<int,int>freq;

    for(int i=0;i<n;i++)
    {
      cin>>k;
      for(int j=0;j<k;j++)
      {
        cin>>bit;
        v[i].push_back(bit);
        freq[bit]++;
      }
    }
    bool flag=true;

    for(int i=0;i<n;i++)
    {
      flag=true;
      for(int j=0;j<v[i].size();j++)
      {
        if(freq[v[i][j]]==1)
        {
          flag=false;
          break;
        }
      }
      if(flag)
      {
        cout<<"YES"<<endl;
        break;
      }
    }

    if(!flag)cout<<"NO"<<endl;
  }
}


 
