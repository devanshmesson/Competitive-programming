#include<bits/stdc++.h>
using namespace std;

#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define int long long int
#define endl "\n"



main()
{
//  freopen
 int t;
 cin>>t;
 while(t--)
 {
  string s;
  cin>>s;
  
  int ok=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]!='a'){ok=1;break;}
  }

  if(ok==0){cout<<"NO"<<endl;continue;}

  if(s.size()==1){cout<<"YES"<<endl;continue;}

  int i=0,j=s.size()-1;
  cout<<"YES"<<endl;

  while(i<=j)
  {

    if(i==j)
    {
      for(int k=0;k<i;k++)cout<<s[k];
      cout<<"a";
      for(int k=i;k<s.size();k++)cout<<s[k];
      cout<<endl;
      break;
    }
    if(s[i]!='a' && s[j]!='a')
    {
      for(int k=0;k<i;k++)cout<<s[k];
      cout<<"a";
      for(int k=i;k<s.size();k++)cout<<s[k];
      cout<<endl;
      break;
    }

    if(s[i]!=s[j])
    {
      if(s[i]=='a')
      {
        for(int k=0;k<i;k++)cout<<s[k];
        cout<<"a";
        for(int k=i;k<s.size();k++)cout<<s[k];
        cout<<endl;
        break;
      }
      else if(s[j]=='a')
      {
        for(int k=0;k<j;k++)cout<<s[k];
        cout<<"a";
        for(int k=j;k<s.size();k++)cout<<s[k];
        cout<<endl;
        break;
      }
    }

    i++; j--;
  }

 }
}
