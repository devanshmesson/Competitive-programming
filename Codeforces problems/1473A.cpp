#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"
#define int long long int
main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,d,x,ok=0;
      cin>>n>>d;
      vector<int>a;
      for(int i=0;i<n;i++)
        {
          cin>>x;
          a.pb(x);
          if(x>d)ok=1;
        }
        if(ok==0){cout<<"YES"<<endl;continue;}

        sort(a.begin(),a.end());
        if(a[0]+a[1]<=d)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
