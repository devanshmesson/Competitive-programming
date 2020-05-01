//Author-Devansh
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       set<int>s;
       vector<int>v;
       int a;
       for(int i=0;i<n;i++)
       {
           cin>>a;
           v.pb(a);
           s.insert(a);
       }
       if(s.size()>k){cout<<-1<<endl;continue;}
       if(n==k)
       {
           cout<<n<<endl;
           for(int i=0;i<n;i++)cout<<v[i]<<" ";
           cout<<endl;
           continue;
       }
       set<int>::iterator j;
       vector<int>f(n+100);
       int x=0,cn=0;
       for(j=s.begin();j!=s.end();j++)
       {
           f[x]=*j;
           x++;
           cn++;
       }
      vector<int>c(n+100);
      int w=0,m=0;
      cout<<n*k<<endl;
       for(int i=0;i<n;i++)
       {
          w=0;
          for(int j=0;j<k;j++)
          {
            cout<<f[w]<<" ";
            w++;
            if(w>=cn)w=w%(cn);
          }
        }
      cout<<endl;

    }

     return 0;
}
