#include <iostream>
#include<process.h>
 
using namespace std;
 
int main()
{
   long long int n,t,k;
   int cnt=0,cnt1=0;
   cin>>n;
   t=n;
 
   while(t!=0)
   {
     k=t%10;
     t=t/10;
      if(k==4) cnt++;
      else if(k==7)cnt1++;
      else continue;
 }
int p=cnt1 +cnt;
   if(p==4 || p==7)
   {
       cout<<"YES";
   }
   else
   {
       cout<<"NO";
   }
 
    return 0;
}
