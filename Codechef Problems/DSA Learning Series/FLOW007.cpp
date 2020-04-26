#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       string s=to_string(n);
       int i=0;
       reverse(s.begin(),s.end());
         while(s[i]=='0'){s[i]=' ';i++;}
      for(int i=0;i<s.size();i++)if(s[i]!=' ')cout<<s[i];
       cout<<endl;
   }
    return 0;
}


