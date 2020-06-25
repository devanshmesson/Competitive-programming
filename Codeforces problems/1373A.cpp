#include<bits/stdc++.h>
using namespace std;
int main() 
{
  #define int long long int
   int t;
   cin>>t;
   while(t--)
   {
      int a,b,c;
      cin>>a>>b>>c;
      if(a>c)cout<<-1<<" "<<b<<endl;
      else if(a<c)
      {
        if(b*a>c)cout<<1<<" "<<b<<endl;
        else if(b*a<=c)cout<<1<<" "<<-1<<endl;
      }
      else if(a==c)cout<<-1<<" "<<b<<endl;
   }
}
