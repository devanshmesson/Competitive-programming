include<bits/stdc++.h>
using namespace std;
define int long long int

bool bi (int x)  
{ 
   return x && (!(x&(x-1)));  
}  
main() 
{
  int t;
  cin>>t;
  while(t--)
  {
    int a,b,ans=0,flag=0;
    int p[]={0,2,4,8};
    cin>>a>>b;
    if(a==b){cout<<0<<endl;continue;}
    if(a>b)swap(a,b);
      int need=b/a;
      if(bi(need)==1 && b%a==0)
      {
        while(1)
        {
          if(need%8!=0)break;
          need/=8;
          ans++;
        }
       if(need==1){flag=1;cout<<ans<<endl;continue;}
       while(1)
        {
          if(need%4!=0)break;
          need/=4;
          ans++;
        }
        if(need==1){flag=1;cout<<ans<<endl;continue;}

        while(1)
        {
          if(need%2!=0)break;
          need/=2;
          ans++;
        }
        if(need==1){flag=1;cout<<ans<<endl;continue;}
        if(flag==0){cout<<-1<<endl;continue;}
      }
      else cout<<-1<<endl;
 }
} 
