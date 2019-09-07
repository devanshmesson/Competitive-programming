#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,a,sum=0,temp=0;
   cin>>n;
   int v[n]={0},b[n],c[n];
   for(int i=1;i<=n;i++)
   {
       cin>>v[i];
   }
   for(int i=1;i<=n;i++)
   {
       cin>>b[i];
   }
   for(int i=1;i<=n-1;i++)
   {
       cin>>c[i];
   }
   for(int i=1;i<=n;i++)
   {
       temp=v[i];
       sum=sum+b[temp];
       if(v[i]==v[i-1]+1 && i!=1)
       {
           sum=sum+c[temp-1];
       }

   }
   cout<<sum;
}
