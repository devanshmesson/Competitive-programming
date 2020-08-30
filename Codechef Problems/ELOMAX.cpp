#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pb push_back

bool sortbysec(pair<int,int>&a , pair<int,int>&b)
{
  return a.first>b.first;
}

main()
{ 
 io
 int t;
 cin>>t;
 while(t--)
 {
    int n,m,sum,mx,in,ans;
    cin>>n>>m;
    int r[501],a[501][501],rating[501];
    int rank[501][501];
    for(int i=0;i<n;i++)cin>>r[i];

    for(int i=0;i<n;i++)
    {
        sum=r[i],mx=INT_MIN,in;
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            sum+=a[i][j];
            rank[i][j]=sum;
            if(mx<sum)
            {
                mx=sum;
                in=j;
            }
        }
        rating[i]=in;
    }

    int best[501][501],c;

    for(int j=0;j<m;j++)
    {
        c=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
           v.pb({rank[i][j],i});
        }
        sort(v.begin(),v.end(),sortbysec);

       
        for(int k=0;k<n;k++)
        {
          c++;
          if(v[k].first==v[k-1].first && k>=0)best[v[k].second][j]=best[v[k-1].second][j];
          else if(v[k].first!=v[k-1].first && k>=0)best[v[k].second][j]=c;
        }
    }
 

    int ranking[501];
    for(int i=0;i<n;i++)
    {
        ans=INT_MAX,in;
        for(int j=0;j<m;j++)
        {
           if(ans>best[i][j])
           {
             in=j;
             ans=best[i][j];
           } 
        }
        ranking[i]=in;
    }

    int an=0;
    for(int i=0;i<n;i++)
    {
        if(ranking[i]!=rating[i])an++;
    }

cout<<an<<endl;
 }
}
