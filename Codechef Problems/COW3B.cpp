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


    int n,m,a;
    cin>>n;
    vector<int>v;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.pb(a);
    }
    cin>>m;
      vector<int>x;
       vector<int>f(1000001);
    for(int i=0;i<m;i++)
    {
        cin>>a;
        x.pb(a);
        f[a]++;
    }
    int flag=1,c=0;

    for(int i=0;i<n;i++)
    {
      if(f[v[i]]==1){flag=0;}
      else {if(flag==0){c++;} flag=1;}
    }
    if(flag==0)c++;
    cout<<c<<endl;
    }
    return 0;
}
