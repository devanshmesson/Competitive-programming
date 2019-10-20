#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n;
        vector<int>v,h;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
            h.push_back(a);
        }
       sort(v.begin(),v.end());
      // cout<<v[0]<<" "<<v[n-1];
       int temp,t;

       for(int i=0;i<n;i++)
       {
           if(v[0]==h[i]){temp=i;break;}
       }
       for(int i=0;i<n;i++)
       {
           if(v[n-1]==h[i]){t=i;break;}
       }


       if(temp<t)cout<<v[0]<<" "<<v[n-1]<<endl;
       else cout<<v[n-1]<<" "<<v[0]<<endl;

    }
    return 0;
}
