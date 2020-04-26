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
       int n,k,a,flag=1;
       cin>>n>>k;
       vector<int>v,h;
       for(int i=0;i<n;i++)
       {
           cin>>a;
           v.pb(a);
           h.pb(a);
       }
       vector<int>c;
       int d[n+20];

       for(int i=0;i<k;i++)
       {
           for(int j=i;j<n;j+=k)
           {
               c.pb(v[j]);
           }
            sort(c.begin(),c.end());
            int f=0;
            for(int j=i;j<n;j+=k)
           {
                d[j]=c[f];
                f++;
           }
           c.clear();
       }
       sort(h.begin(),h.end());
       for(int i=0;i<n;i++)
       {
           if(h[i]!=d[i]){flag=0;break;}
       }
       if(flag==1)cout<<"yes"<<endl;
       else cout<<"no"<<endl;

    }
    return 0;
}
