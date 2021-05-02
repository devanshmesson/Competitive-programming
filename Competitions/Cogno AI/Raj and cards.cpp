//Link to problem - https://www.hackerrank.com/contests/crack-the-code-to-cogno-ai/challenges/raj-and-cards

#include<bits/stdc++.h>
using namespace std;
// #define int  long long int
#define endl "\n"
#define freopen freopen("input.txt","r",stdin);freopen("output1.txt","w",stdout);
#define pb push_back
// Taskkill /IM a.exe /F

int main()
{
  // freopen
  int t;
  cin>>t;
  while(t--)
  {
    int mp[123];
    string s,spell;
    cin>>s;
    cin>>spell;


    // cout<<"hi"<<endl;
    // break;
    
    for(int i=0;i<s.size();i++)
    {
      mp[s[i]]=i;
    }


    int sum=0,upd=0;
    for(int i=0;i<spell.size();i++)
    {
      char req=spell[i];
      sum+=abs(mp[req]-upd);
      upd=mp[req];
    }
    cout<<sum<<endl;


  }
}
