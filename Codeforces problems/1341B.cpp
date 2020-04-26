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
       int n,k,z;
       cin>>n>>k;
       vector<int>v;
       for(int i=0;i<n;i++)
       {
           cin>>z;
           v.pb(z);
       }
       vector<int>a(n+1);
       vector<int>pre(n+1);
       int s=0;
       for(int i=1;i<n-1;i++)
       {
         if(v[i]>v[i+1] && v[i]>v[i-1])
         {
             a[i]=1;
             s+=a[i];
             pre[i]=s;
         }
         else
         {
             pre[i]=s;
         }
       }
       int m=INT_MIN,c,in;
       for(int l=0;l<n-k+1;l++)
       {
         c=pre[l+k-2]-pre[l];
         if(m<c)
         {
             m=c;
             in=l+1;
         }
       }
       cout<<m+1<<" "<<in<<endl;


    }
    return 0;
}
