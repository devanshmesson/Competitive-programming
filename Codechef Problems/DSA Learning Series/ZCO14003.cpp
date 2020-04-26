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
   int r=t;
   vector<int>v;
   while(t--)
   {
     int n;
     cin>>n;
     v.pb(n);
   }
   sort(v.begin(),v.end());
   int m=INT_MIN;
   for(int i=0;i<r;i++)
   {
       m=max(m,v[i]*(r-i));
   }
   cout<<m<<endl;
    return 0;
}


