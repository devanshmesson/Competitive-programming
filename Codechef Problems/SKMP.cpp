#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define pb push_back
#define int long long int
#define endl "\n"
const int MAX_CHAR = 26; 

void sorts(string &str,string &dd) 
{ 
    int charCount[MAX_CHAR] = {0}; 
    for (int i=0; i<str.length(); i++) charCount[str[i]-'a']++;     
      
    for (int i=0;i<MAX_CHAR;i++) 
        for (int j=0;j<charCount[i];j++) 
            dd+=(char)('a'+i); 
} 

main()
{ 
  int tt;
  cin>>tt;
  while(tt--)
  {
    string s,t,ans,dd;
    cin>>s>>t;
    if(s.size()==t.size()){cout<<t<<endl;continue;}
    char mx='a';
    map<char,int>mp;

    for(char x:t)
      {
        mx=max(mx,x);
        mp[x]++;
      }
      for(char x:s)
      {
        if(mp[x])mp[x]--;
        else ans.pb(x);
      }
      sort(ans.begin(),ans.end());
      int ind,flag=0,start,yes=0,less=-1,more=-1;

      for(int i=0;i<ans.size();i++)
      {
        if(ans[i]==t[0])
          {
            start=i;
            yes=1;
            break;
          }
      }    
      int morflag=0;
      for(int i=0;i<ans.size();i++)
      {
        if(ans[i]==t[0])
          {
            ind=i;
            flag=1;
          }
        else if(ans[i]<t[0])
        {
          less=i;
        }
        else if(ans[i]>t[0] && morflag==0)
        { 
          more=i;
          morflag=1;
        }
      }
      int situate;
      if(flag)
      {
        if(mx>=t[0])
        { 
         situate=ind+1;
        }
        else
        {
          situate=start;
        }
      }
      string one,two,thri;
      if(yes)
      {
        for(int i=0;i<situate;i++)one.pb(ans[i]);
        for(int i=0;i<t.size();i++)one.pb(t[i]);
        for(int i=situate;i<ans.size();i++)one.pb(ans[i]);
      }
        if(less!=-1)
        {
          for(int i=0;i<=less;i++)two.pb(ans[i]);
          for(int i=0;i<t.size();i++)two.pb(t[i]);
          for(int i=less+1;i<ans.size();i++)two.pb(ans[i]);
        }
        if(more!=-1)
       {
        for(int i=0;i<more;i++)thri.pb(ans[i]);
        for(int i=0;i<t.size();i++)thri.pb(t[i]);
        for(int i=more;i<ans.size();i++)thri.pb(ans[i]);
       } 
      vector<string>fin;
      int ss=0;
      if(one.size()>0){fin.pb(one);ss++;}
      if(two.size()>0){fin.pb(two);ss++;}
      if(thri.size()>0){fin.pb(thri);ss++;}
     string lex=fin[0];
     for(int i=0;i<fin.size();i++)
     {
        lex=min(lex,fin[i]);
     }
     cout<<lex<<endl; 
  } 
}
