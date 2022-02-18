// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double


string GetRuler(const string& kingdom) 
{
  string ruler = "";
  int sz=kingdom.size();
  char vowels[]={'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
  bool alice=false;
  for(int i=0;i<10;i++)
  {
    alice|=(kingdom[sz-1]==vowels[i]);
  }
  if(alice)ruler+="Alice";
  else if(kingdom[sz-1]=='y' || kingdom[sz-1]=='Y')ruler+="nobody";
  else ruler+="Bob";
  return ruler;
}

signed main() 
{
//   freopen
  ios
  int testcases;
  cin >> testcases;
  string kingdom;

  for (int t = 1; t <= testcases; ++t) 
  {
    cin >> kingdom;
    cout << "Case #" << t << ": " << kingdom << " is ruled by "
         << GetRuler(kingdom) << ".\n";
  }
  return 0;
}

    
