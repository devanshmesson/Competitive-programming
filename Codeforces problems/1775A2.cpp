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
//   freopen
  int  t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int n = s.size();

    if(s[0]=='a' && s[n-1]=='b')
    {
      if(s[1]=='b')
      {
        cout<<s[0]<<" "<<s.substr(1,n-2)<<" "<<s[n-1]<<endl;
      }
      else
      {
        cout<<s.substr(0,n-2)<<" "<<s[n-2]<<" "<<s[n-1]<<endl;
      }
    }
    else if(s[0]=='b' && s[n-1]=='a')
    {
      if(s[1]=='b')
      {
        cout<<s[0]<<" "<<s.substr(1,n-2)<<" "<<s[n-1]<<endl;
      }
      else
      {
        cout<<s[0]<<" "<<s[1]<<" "<<s.substr(2,n-2)<<endl;
      }
    }
    else 
    {
      cout<<s[0]<<" "<<s.substr(1,n-2)<<" "<<s[n-1]<<endl;
    }
  }
}
 
