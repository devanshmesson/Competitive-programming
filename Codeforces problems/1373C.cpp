#include<bits/stdc++.h>
using namespace std;
int main() 
{
   #define int long long int
   int t;
   cin>>t;
   while(t--)
   {
     string s;
     cin>>s;
     int num=0,num0=0,ans=s.size();
     for(int i=0;i<s.size();i++)
     {
       if(s[i]=='+')num++;
       else num--;
       if(num<0){ans+=(i+1);num=0;}
     }
     cout<<ans<<endl;
  }
}
