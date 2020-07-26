#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string a,b;
    cin>>a>>b;
    int minans=a.size(),maxans=0;
    for(int i=0;i<a.size();i++)
    {
      if((a[i]!='?' && b[i]=='?')||(a[i]=='?' && b[i]=='?')||(a[i]=='?' && b[i]!='?'))
      {
        minans--;
        maxans++;
      }
      else if(a[i]!=b[i] && a[i]!='?' && b[i]!='?')
      {
        maxans++;
      }
      else if(a[i]==b[i] && a[i]!='?' && b[i]!='?')
      {
        minans--;
      }
    }
    cout<<minans<<" "<<maxans<<endl;
  }
}


