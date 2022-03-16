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
   int x1,y1,x2,y2;
   cin>>x1>>y1>>x2>>y2;
   x1--,y1--,x2--,y2--;
   int a[n][m];
   int turn=1;
   int viol=0;
   for(int i=0;i<n;i++)
   {
    if(i%2==0)turn=1;
    else turn=2;
    for(int j=0;j<m;j++)
    {
      a[i][j]=turn;
      turn=3-turn;
      // cout<<a[i][j]<<" ";
    }
    // cout<<endl;
   }
   // cout<<a[x1][y1]<<" "<<a[x2][y2]<<endl;

   if(a[x1][y1]==1 && a[x2][y2]==2)
   {
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<m;j++)
      {
       cout<<a[i][j]<<" ";
      }
      cout<<endl;
     }
     continue;
   }
    if(a[x1][y1]!=1 && a[x2][y2]!=2)
    {
     for(int i=0;i<n;i++)
     {
      if(i%2==0)turn=2;
      else turn=1;
      for(int j=0;j<m;j++)
      {
        a[i][j]=turn;
        turn=3-turn;
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
     }
     continue;
    }

    if(a[x1][y1]==1)
    {
      if(x2-1>=0)a[x2-1][y2]=3;
      if(x2+1<n)a[x2+1][y2]=3;
      if(y2-1>=0)a[x2][y2-1]=3;
      if(y2+1<m)a[x2][y2+1]=3;
      a[x2][y2]=2;

      for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
         cout<<a[i][j]<<" ";
        }
        cout<<endl;
       }
       continue;
    }

    if(a[x1][y1]==2)
    {

      if(x1-1>=0)a[x1-1][y1]=3;
      if(x1+1<n)a[x1+1][y1]=3;
      if(y1-1>=0)a[x1][y1-1]=3;
      if(y1+1<m)a[x1][y1+1]=3;
      a[x1][y1]=1;
      for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
         cout<<a[i][j]<<" ";
        }
        cout<<endl;
       }
       continue;
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
    
    
