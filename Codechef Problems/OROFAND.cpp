// #pragma GCC optimize "trapv"
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define pb push_back
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,q;
    cin>>n>>q;
    int a[n+1];
    int oro=0;
    for(int i=1;i<=n;i++){cin>>a[i];oro = oro | a[i];} 
    cout<<oro<<endl;
    
    int record[31]={0};
    for(int i=0;i<=30;i++)
    {
      int bit=1<<i;
      for(int j=1;j<=n;j++)
      {
        int op=bit & a[j];
        if(op!=0)record[i]++;
      }
    }



    for(int qq=0;qq<q;qq++)
    {
      int x,v;
      cin>>x>>v;
      
      for(int i=0;i<31;i++)
      {
        int bit=1<<i;
        int con = bit & a[x];
        if(con!=0)  //was it contributing?
        {
          record[i]--;
          if(record[i]==0)
          {
            oro-=(1<<i);
          }
        }
      }
       a[x]=v;     
       for(int i=0;i<31;i++)
       {
        int bit=1<<i;
        int con=bit & a[x];
        if(con!=0)  //Is it contributing?
        {
          record[i]++;
          if(record[i]==1)
          {
            oro+=(1<<i);
          }
        }
      }
      cout<<oro<<endl;

    }
  }
}
