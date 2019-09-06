#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,sum=0,flag=0,temp,a;
   vector<int> v;
   cin>>n;
   for(int i=0;i<7;i++)
   {
       cin>>a;
       v.push_back(a);
   }

   for(int i=0;i<1000;i++)
   {
       for(int j=0;j<7;j++)
       {
          sum+=v[j];
          temp=j+1;
          if(sum>=n) {flag=1;break;}
       }
       if(flag==1)break;
   }
   cout<<temp<<endl;
    return 0;
}
