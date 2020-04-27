#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    //#define endl "\n"
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n;
        vector<int>v;
        set<int>s;
        for(int i=0;i<n;i++)
        {
          cin>>a;
          v.pb(a);
          s.insert(a);
        }
        int c=0,u,m=INT_MIN,ans;
        set<int>::iterator i;
        for(i=s.begin();i!=s.end();i++)
        {
            c=0;
            u=INT_MIN;
            for(int j=0;j<n;j++)
            {
               if(v[j]==*i && abs(j-u)!=1)
               {
                   c++;
                   u=j;
               }
            }
            if(m<c)
            {
                m=c;
                ans=*i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
