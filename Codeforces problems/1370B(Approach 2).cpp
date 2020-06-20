#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m=INT_MIN,a;
    cin>>n;
   vector<int>e,o;
   int stop=0;
    for(int i=0;i<(2*n);i++)
    {
      cin>>a;
      if(a%2==0)e.pb(i);
      else o.pb(i);
    }
    if(e.size()%2==0 && o.size()%2==0)
    {
      
      if(e.size()>0)
      {
       for(int i=0;i<(e.size()-2);i+=2)
       {
        cout<<e[i]+1<<" "<<e[i+1]+1<<endl;
        stop++;
        if(stop==n-1)break;
       }
      }
      if(o.size()>0)
      {
       for(int i=0;i<o.size();i+=2)
       {
        cout<<o[i]+1<<" "<<o[i+1]+1<<endl;
        stop++;
        if(stop==n-1)break;
       }
      }
    }
    else if(e.size()%2!=0 && o.size()%2!=0)
    {
      if(e.size()>0)
      {
       for(int i=0;i<(e.size()-1);i+=2)
       {
        cout<<e[i]+1<<" "<<e[i+1]+1<<endl;
        stop++;
        if(stop==n-1)break;
       }
      }
      if(o.size()>0)
      {
        for(int i=0;i<(o.size()-1);i+=2)
        {
        cout<<o[i]+1<<" "<<o[i+1]+1<<endl;
        stop++;
        if(stop==n-1)break;
        }
      }
      
    }

   cout<<endl;
  }
 }
