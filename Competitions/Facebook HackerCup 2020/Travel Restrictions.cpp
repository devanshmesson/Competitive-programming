//https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/A#
#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
main()
{
  io
  int t;
  cin>>t;
  for(int tt=1;tt<=t;tt++)
  {
    int n;
    cin>>n;
    char inc[n+2],out[n+2],ans[n+2][n+2];
     for(int i=1;i<=n;i++)
     {
      for(int j=1;j<=n;j++)
      {
       ans[i][j]='Q';
      }
     }

    for(int i=1;i<=n;i++)cin>>inc[i];
    for(int i=1;i<=n;i++)cin>>out[i];

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {

        if(i==j){ans[i][j]='Y';continue;}

        else if(abs(i-j)==1)
        {
          if(out[i]=='Y' && inc[j]=='Y')ans[i][j]='Y';
          else ans[i][j]='N';
        }
        else if(abs(i-j)>1)
        {

          if(i>j)
          {
            int stop=abs(i-j);
            int in=i;
            while(stop>0)
            {

              if(ans[in][in-1]!='Q')
              {
               
                if(ans[in][in-1]=='Y')
                  {
                    if(in-1==j)ans[i][j]='Y';
                    in--;
                  }
                else if(ans[in][in-1]=='N')
                  {
                    ans[i][j]='N';
                    break;
                  }
              }
              else if(ans[in][in-1]=='Q')
              {
                
                if(out[in]=='Y' && inc[in-1]=='Y')
                  {
                    ans[in][in-1]='Y';
                    if(in-1==j)ans[i][j]='Y';
                    in--;
                  }
                else 
                  {
                    
                    ans[in][in-1]='N';
                    ans[i][j]='N';
                    break;
                  }
              }
              stop--;
            }
          }
          else if(i<j)
          {
            int stop=abs(i-j);
            int ini=i;
            while(stop>0)
            {

              if(ans[ini][ini+1]!='Q')
              {
                
                if(ans[ini][ini+1]=='Y')
                  {
                    if(ini+1==j)ans[i][j]='Y';
                    ini++;
                  }
                else if(ans[ini][ini+1]=='N')
                  {
                    ans[i][j]='N';
                    break;
                  }
              }
              else if(ans[ini][ini+1]=='Q')
              {
                if(out[ini]=='Y' && inc[ini+1]=='Y')
                  {
                    ans[ini][ini+1]='Y';
                    if(ini+1==j)ans[i][j]='Y';
                    ini++;
                  }
                else 
                  {
                    ans[ini][ini+1]='N';
                    ans[i][j]='N';
                    break;
                  }
              }
              stop--;
            }
          }
        }
      }
    }
    cout<<"Case #"<<tt<<":"<<endl;

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cout<<ans[i][j];
      }
      cout<<endl;
    } 
  }
}
