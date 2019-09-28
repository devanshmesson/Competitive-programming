#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,a;
   cin>>n;
   int ar[100000];
   for(int i=1;i<=n;i++)
   {
       cin>>a;
       ar[a]=i;
   }
   for(int i=1;i<=n;i++)
   {
       cout<<ar[i]<<" ";
   }

    return 0;
}
