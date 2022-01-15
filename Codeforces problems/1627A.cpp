#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    char a[n+1][m+1];
    int flag=0,yes=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin>>a[i][j];
        if(a[i][j]=='B')
          {
            if(i==r || j==c)yes=1;
            flag=1;
          }
      }
    }
    if(a[r][c]=='B'){cout<<0<<endl;continue;}
    if(flag==0){cout<<-1<<endl;continue;}
    if(yes==1){cout<<1<<endl;continue;}
    cout<<2<<endl;
  }

}
/*1.Never overkill a problem.
 2.think of test cases to clarify the approach/doubts.
*/ 
