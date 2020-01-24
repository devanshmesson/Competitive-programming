#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,x=0,y=0,r=0,u,flag=1;
        cin>>n;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b; v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());

        for(int i=0;i<n-1;i++)
        {
            if(v[i].first<v[i+1].first && v[i].second>v[i+1].second){flag=0;break;}
        }
        if(flag==0){cout<<"NO"<<endl;}
        else
        {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
          r=abs(x-v[i].first);
          x=v[i].first;
          for(int j=0;j<r;j++)cout<<"R";
          u=abs(y-v[i].second);
          y=v[i].second;
          if(y<=v[i-1].second  && i!=0){y=v[i-1].second;continue;}
          else if(y>v[i-1].second  && i!=0){u=abs(v[i-1].second-y);}
          for(int j=0;j<u;j++)cout<<"U";
        }
        cout<<endl;
        }

    }
    return 0;
}
