#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio();cin.tie();cout.tie();
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,a,b,d1,d2,d3;
        cin>>n>>x>>a>>b;
       if(max(a,b)==n && min(a,b)==1){cout<<n-1<<endl;continue;}
       if(x==0){cout<<max(a,b)-min(a,b)<<endl;continue;}
        d1=fabs(n-max(a,b));
        d2=fabs(min(a,b)-1);
         d3=fabs(a-b);
       if(d1>=d2)
       {
           while(1)
           {
               if(x==0)break;
               if(d1==0)break;
              x--;
              d3++;
              d1--;
           }
           if(x!=0 && d1==0)
           {
               while(1)
               {
                   if(x==0)break;
                   if(d2==0)break;
                   x--;
                   d3++;
                   d2--;
               }
           }
           cout<<d3<<endl;
       }
       else if(d2>d1)
       {
           while(1)
           {
               if(x==0)break;
               if(d2==0)break;
               x--;
               d3++;
               d2--;
           }
           if(x!=0 && d2==0)
           {
               while(1)
               {
                   if(x==0)break;
                   if(d1==0)break;
                   x--;
                   d3++;
                   d1--;
               }
           }
 
           cout<<d3<<endl;
       }
 
    }
 
 
    return 0;
}
