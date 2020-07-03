#include<bits/stdc++.h>
using namespace std;
main() 
{
   int n,k,a,cnt=0;
   cin>>n>>k;
   for(int i=0;i<n;i++)
   {
     cin>>a;
     if(a%k==0)cnt++;
   }
   cout<<cnt<<endl;
  return 0;
}
