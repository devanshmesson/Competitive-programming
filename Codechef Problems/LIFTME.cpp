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
         int n,q,s,w;
         cin>>n>>q;
         vector<int>a,b;
         int sum=0;
         for(int i=0;i<q;i++)
         {
             cin>>s;a.pb(s);
             cin>>w;b.pb(w);
         }
         sum+=abs(0-a[0]);
         for(int i=0;i<q;i++)
         {
             sum+=abs(a[i]-b[i]);
             if(i<q-1)sum+=abs(b[i]-a[i+1]);
         }
         cout<<sum<<endl;
     }




    return 0;
}
