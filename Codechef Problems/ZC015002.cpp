#include <iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  long long  int n,k,cnt=0;
   cin>>n;
   cin>>k;
   long long int a[n];

   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   sort(a,a+n);


   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
        int p=a[i]-a[j];
          if(fabs(p)>=k)
           {
               cnt+=n-j;
               break;
           }
       }
   }
   cout<<cnt;


    return 0;
}
