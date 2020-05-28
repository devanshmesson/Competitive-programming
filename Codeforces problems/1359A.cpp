#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
 {   
   int n,m,k,maxi,add=0;
   cin>>n>>m>>k;

   int mil=min(n/k,m);
   m-=mil;
   if(m>0 && k-1>0)
   {
    if(m%(k-1)!=0)add=1;
     maxi=m/(k-1)+add;
     cout<<mil-maxi<<endl;
   }
   else cout<<mil<<endl;
   
 }
}
