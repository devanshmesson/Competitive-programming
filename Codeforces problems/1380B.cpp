#include<bits/stdc++.h>
using namespace std;
main() 
{
   #define int long long int 
   int t;
   cin>>t;
   while(t--)
   {
     string s;
     cin>>s;
     vector<pair<int,char>>ans;
     int a=0,b=0,c=0;
     for(int i=0;i<s.size();i++)
     {
      if(s[i]=='R')a++;
      else if(s[i]=='P')b++;
      else c++;
     }
     ans.pb({a,'R'});
     ans.pb({b,'P'});
     ans.pb({c,'S'});
     sort(ans.begin(),ans.end());
     char print;
     if(ans[2].second=='R')print='P';
     else if(ans[2].second=='P')print='S';
     else print='R';
     for(int i=0;i<s.size();i++)cout<<print;
     cout<<endl;
   }
  return 0;
}
