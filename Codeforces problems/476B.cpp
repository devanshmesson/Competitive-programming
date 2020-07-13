#include<bits/stdc++.h>
using namespace std;
main() 
{
   #define int long long int 
   double ans;
   string s,t;
   cin>>s>>t;
   int sz=s.size();
   int val=0;  
   for(int i=0;i<sz;i++)
   {
    if(s[i]=='+')val++;
    else val--;
   }
   int ok=1,valu=0,q=0;
   for(int i=0;i<sz;i++)
   {
    if(t[i]=='?'){ok=0;q++;}
    if(t[i]=='+')valu++;
    else if(t[i]=='-')valu--;
   }

   if(val==valu && ok){ans=1;cout<<setprecision(10)<<fixed<<ans<<endl;return 0;}
   else if(val!=valu && ok){ans=0;cout<<setprecision(10)<<fixed<<ans<<endl;return 0;}
   int fin;
   double num=0.0,den=(1<<q);
   for(int i=0;i<den;i++)
   {
     fin=valu;
     bitset<10>bit(i);
     for(int j=0;j<q;j++)
     {
      if(bit[j])fin++;
      else fin--;
     }
     if(fin==val)num++;
   }
   ans=num/den;
   cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}
