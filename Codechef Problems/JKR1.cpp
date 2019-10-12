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
        int n;
        string s;
        vector<pair<string,int> > v;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            v.push_back(make_pair(s,s.size()));
        }
        for(int i=v[n-1].second-1;i>=0;i--)
        {
            cout<<v[n-1].first[i];
        }
        cout<<" ";
        int temp=0,cnt=0;
        for(int i=0;i<n/2;i++)
        {
            if(i!=n-1 && temp!=n-1)
            {
           cout<<v[i].first<<" ";
           temp=n-i-2;
           if(temp==i)break;
           cout<<v[temp].first<<" ";
            }


        }
    }
    return 0;
}
