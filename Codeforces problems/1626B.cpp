#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
  int t;
  cin>>t;
 for(int tt=1;tt<=t;tt++)
  {
    string s;
    cin>>s;
    int n=s.size();
    if(n==1){cout<<1<<endl;continue;}
    int flag=1;
    for(int i=0;i<n-1;i++)
    {
      int a=(int)s[i]-48;
      int b=(int)s[i+1]-48;
      if(a+b>=10){flag=0;break;}
    }
    if(flag==1)
    {
      int ok=0;
      if(s[1]=='0')
      {
        int a=(int)s[0]-48;
        int b=(int)s[1]-48;
        s[0]=to_string((a+b))[0];
        s[1]='a';  
        ok=1;
      }
      if(ok==0)
      {
       for(int i=0;i<n-1;i++)
       {
         int a=(int)s[i]-48;
         int b=(int)s[i+1]-48;
         if(a>0 && b>0)
         {
           s[i]=to_string((a+b))[0];
           s[i+1]='a';
           ok=1;
           break;
         }
       }
     }
     if(ok==0)
     {
      for(int i=0;i<n-1;i++)
      {
        int a=(int)s[i]-48;
        int b=(int)s[i+1]-48;
        if(a+b>0)
        {
          s[i]=to_string((a+b))[0];
          s[i+1]='a';
          ok=1;
          break;
        }
      }
     }
     if(ok==0)
     {
      int a=(int)s[0]-48;
      int b=(int)s[1]-48;
      s[0]=to_string((a+b))[0];
      s[1]='a';  
     }
    }
    else
    {
      for(int i=n-1;i>=1;i--)
      {
         int a=(int)s[i]-48;
         int b=(int)s[i-1]-48;
         if(a+b>=10)
        {
          s[i-1]=to_string((a+b))[0];
          s[i]=to_string((a+b))[1];
          break;
        }

      }
    }
    for(int i=0;i<n;i++)
    {
      if(s[i]!='a')cout<<s[i];
    }
    cout<<endl;
  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
*/ 
