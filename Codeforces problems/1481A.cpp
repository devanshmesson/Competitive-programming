#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
#define endl "\n"

main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int x,y;
      cin>>x>>y;
      string s;
      cin>>s;
      int s1=0,s2=0,ok1=0,ok2=0,s3=0,s4=0;
      for(int i=0;i<s.size();i++)
      {
         if(s[i]=='D')s3--;
         else if(s[i]=='U')s2++;

         if(s2==y)ok1=1;
         if(s3==y)ok1=1;

         if(s[i]=='R')s1++;
         else if(s[i]=='L')s4--;

         if(s1==x)ok2=1;
         if(s4==x)ok2=1;
      }
      if(ok1==1 && ok2==1)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
}
