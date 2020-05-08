#include<bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

     int n,m,c,cn=0,v=0,z=0;
     cin>>n;

     vector<int>a;
     vector<int>b;
     for(int i=0;i<n;i++)
     {
         cin>>c;
         if(c<0){cn++;a.push_back(c);}
         else if(c>0){b.push_back(c);v++;}
         else if(c==0){z++;}
     }
     int cost=0,k=1,d=1;
     if(cn%2!=0)
     {
         if(z>1)
         {
             cost++;
             z--;
         }
         else if(z==0)cost+=2;
    }
    cost+=z;

     for(int i=0;i<v;i++)cost+=abs(b[i]-1);
     for(int i=0;i<cn;i++)cost+=abs(a[i]+1);
     cout<<cost<<endl;
     return 0;
}
