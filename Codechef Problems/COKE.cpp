#include <bits/stdc++.h>

using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
     int flag=1;
    long long int n,m,k,l,r,a,b;
    vector< pair<long long int,long long int> > v;
    cin>>n>>m>>k>>l>>r;

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
sort(v.begin(),v.end(),sortbysec);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
        if(v[i].first>k+1)
        {
            v[i].first=v[i].first - 1;

        }
        else if(v[i].first<k-1)
        {
           v[i].first=v[i].first + 1;
        }
        else if(v[i].first<=k+1 && v[i].first>=k-1)
        {
            v[i].first=k;
        }
        }
    }
    for(int i=0;i<n;i++)
    {

       if(v[i].first>=l && v[i].first<=r)
        {
            cout<<v[i].second<<endl;
            flag=1;
            break;

        }
        else
        {
            flag=0;
        }
    }
    if (flag==0) cout<<"-1"<<endl;
    }

    return 0;
}
