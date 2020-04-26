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
       int n,s;
       cin>>n>>s;
       int g,q,a,f=1,f1=1;
       int r=100-s;
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++)
       {
            cin>>a;
            v.pb(mk(a,0));
       }
       for(int i=0;i<n;i++)
       {
           cin>>a;
           if(a==1)f=0;
           if(a==0)f1=0;
           v[i].second=a;
       }
       if(f==1 || f1==1){cout<<"no"<<endl;continue;}
       sort(v.begin(),v.end());



       for(int i=0;i<n;i++)
       {
           if(v[i].second==0)
           {
               g=v[i].first;
               break;
           }
       }
       for(int i=0;i<n;i++)
       {
           if(v[i].second==1)
           {
               q=v[i].first;
               break;
           }
       }
       if(g+q<=r)cout<<"yes"<<endl;
       else cout<<"no"<<endl;





    }
    return 0;
}
