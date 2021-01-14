#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"
#define int long long int
main()
{
    int t;
    cin>>t;
    while(t--)
    {
      string s,t;
      int sz;
      cin>>s>>t;
      //equal numbers
      int ss=s.size(),tt=t.size();
      char ar[200]={0};
      for(int i=0;i<s.size();i++)ar[s[i]]++;
      for(int i=0;i<t.size();i++)ar[t[i]]++;
      int till=__gcd(ss,tt);
      till=ss*tt/till;
      
      if((ar[97]>=1 && ar[98]==0))
        {
          for(int i=0;i<till;i++)cout<<"a";
          cout<<endl;
          continue;
        }
        else if(ar[98]>=1 && ar[97]==0)
        {
          for(int i=0;i<till;i++)cout<<"b";
          cout<<endl;
          continue;
        }   
      int ok=1;
      vector<char>ans;
      for(int i=0;i<till;i++)
      {
        if(s[i % ss] != t[i % tt]){ok=0;break;}
        else ans.pb(s[i % ss]);
      }
      if(ok==0){cout<<-1<<endl;}
      else 
      {
       for(auto x:ans)cout<<x;
        cout<<endl;
      }
    }
}
