#include<bits/stdc++.h>
using namespace std;
int main() 
{
   #define int long long int 
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     cin>>n;
     string s;
     cin>>s;
     stack<char>q;
     int done=0; 
     for(int i=0;i<s.size();i++)
     {
      if(s[i]=='(')q.push('(');
      else if(s[i]==')' && !q.empty())
      {
        if(q.top()=='(')
        {
          n-=2;
          q.pop();
        }
      }
     }
     cout<<n/2<<endl;
   }
}
