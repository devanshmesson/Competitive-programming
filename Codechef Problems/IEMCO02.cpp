#include<bits/stdc++.h>
using namespace std;
main()
{
  vector<string>v,orig;
  orig.pb("ACov(A)");
  orig.pb("BCov(B)");
  orig.pb("CCov(C)");
  orig.pb("DCov(D)");
  orig.pb("ECov(E)");
  orig.pb("FCov(F)");
  char check[]={'A','B','C','D','E','F'};
  char cov[]={'C','o','v'};

  map<string,int>mp;
  string s;
  float ans=0;
  while(cin>>s)
  {
    if(mp[s])continue;
    bool flag=0;
    if(s.size()==7)
    {
    for(int i=0;i<6;i++)
    {
      if(s==orig[i] && mp[s]==0)
      {
        mp[s]++;
        ans+=1;
      }
     }
    }
    else if(s.size()==4)
    {
     for(int j=0;j<6;j++)
     {
        flag=1;
       for(int i=1;i<=3;i++)
       {
        if(s[0]==check[j] && s[i]==cov[i-1])
        else {flag=0;}
      }
      if(flag)
      { 
         mp[s]++;
         ans+=0.5;
         break;
      }
     }
     
    }
    else if(s.size()==3)
     {
       for(int i=0;i<6;i++)
       {
        if(s[0]=='(' && s[1]==check[i] && s[2]==')')
        {
          ans+=0.5;
          mp[s]++;
          break;
        }
       }
     }
     else
     {
      for(int i=0;i<6;i++)
       {
        if(s[s.size()-1]==')' && s[s.size()-2]==check[i] && s[s.size()-3]=='(')
        {
          ans+=0.5;
          mp[s]++;
          break;
        }
       }
     }
  }
 cout<<ans<<" "<<"out of 6"<<endl;
}
