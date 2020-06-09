#include<bits/stdc++.h>
using namespace std;
main() 
{
   float b;
   int a;
   cin>>a>>b;
   if(a%5==0 && (a+0.5)<=(b) && a>=5)
   {
    float ans=b-a-0.5;
    //if(ans<0.0)ans=0.00;
    cout<<ans<<endl;
   }
   else cout<<b<<endl;
}
