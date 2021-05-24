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
    int n;
    cin>>n;
    string s;
    cin>>s;

    int good=0,bad=0;
    int flag=0;

    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='1')good++;
      else bad++;

      int life=i+1;
      int plus=0;
      if(life%2==1)plus=1;
      life/=2;
      life+=plus;

      if(good>=life){flag=1;break;}
    }

    if(flag==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
  
}
    
