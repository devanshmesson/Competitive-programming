include<bits/stdc++.h>
using namespace std;
main() 
{
   int t,sum=0;
   cin>>t;
   while(t--)
   {
     string s;
     cin>>s;
     int c1=0,c2=0;
    
     for(int i=0;i<s.size();i++)
     {
      if((int)s[i]>=97 && (int)s[i]<=122)c1++;
      else if(((int)s[i]>=65 && (int)s[i]<=90))c2++;
     }
     
     sum+=abs(c1-c2);

   }
   cout<<sum<<endl;
} 
