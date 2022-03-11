// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    char a[n+1][m+1];
    int ans=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        char x;
        cin>>x;
        a[i][j]=x;
        ans+=(a[i][j]=='1');
      }
    }
    if(a[0][0]=='1'){cout<<-1<<endl; continue;}
    cout<<ans<<endl;

    for(int i=n-1;i>=0;i--)
    {
      for(int j=m-1;j>=0;j--)
      {
        if(i>0 && a[i][j]=='1')
        {
          int x1,y1,x2,y2;
          x1=i-1;
          y1=j;

          x2=i;
          y2=j;

          x1++; y1++; x2++; y2++;
          cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        }
        else if(a[i][j]=='1')
        {

          int x1,y1,x2,y2;
          x1=i;
          y1=j-1;

          x2=i;
          y2=j;

          x1++; y1++; x2++; y2++;
          cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

        }

      }
    }
  }
 
}
    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
