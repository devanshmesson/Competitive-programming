#include<bits/stdc++.h> 
using namespace std;
int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
     string s;
     cin>>s;
     int num1=0,num0=0;
     for(int i=0;i<s.size();i++)
     {
       if(s[i]=='1')num1++;
       else num0++;
     }
     int ans=min(num1,num0);
     if(ans%2!=0)cout<<"DA"<<endl;
     else cout<<"NET"<<endl;
  }
}
