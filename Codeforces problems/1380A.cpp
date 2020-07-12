#include<bits/stdc++.h>
using namespace std;
main() 
{
   #define int long long int 
   int t;
   cin>>t;
   while(t--)
   {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    int flag=1,x=-1,y=-1,z=-1,f=1;
    for(int i=0;i<n;i++)
    {
      x=i;
      flag=1;
      for(int j=x+1;j<n;j++)
      {
       if(a[j]>a[x]){flag=0;y=j;break;} 
      }
      if(flag==0)
      {
        f=1;
        for(int j=y+1;j<n;j++)
        {
          if(a[y]>a[j]){f=0;z=j;break;}
        }
        
        if(f==0)break;
      }
    }
    if(x>=0 && y>0 && z>0)
    {
      cout<<"YES"<<endl;
      cout<<x+1<<" "<<y+1<<" "<<z+1<<endl;
    }
    else cout<<"NO"<<endl;
    
   }
   return 0;
}
