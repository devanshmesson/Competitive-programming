#include<bits/stdc++.h>
using namespace std;

main()
{
  int t;
  cin>>t;
  while(t--)
  {
   int n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   int a[k+1];
   int same=0,diff=0;
   for(int i=1;i<=k;i++)cin>>a[i];
   for(int i=0;i<n-1;i++)
   {
    if(s[i]!=s[i+1])diff++;
    else same++;
   }
   int ans=(same*2)+diff;
   
   for(int i=1;i<=k;i++)
   {
      if(n==1){cout<<0<<endl;continue;}
      int u=a[i],ch;

      if(u==1 || u==n)
      {
        if(u==1)ch=2;
        else ch=n-1;

        if(s[u-1]==s[ch-1])
        {
          ans-=2;
          ans++;
        }
        else
        {
          ans--;
          ans+=2;
        }
      }
      else
      {
        int di=0,si=0;
        for(int g=0;g<=1;g++)
        {
          if(g%2==0)ch=u+1;
          else ch=u-1;
          if(s[u-1]==s[ch-1])
          {
           si++;
          }
        else
        {
          di++;
        }

        }

        if(di==2)
        {
          ans-=2;
          ans+=4;
        }
        else if(si==2)
        {
          ans-=4;
          ans+=2;
        }
        
      }
      cout<<ans<<endl;

      if(s[u-1]=='0')s[u-1]='1';
      else s[u-1]='0';
   }
  
  cout<<endl;

  }
}
