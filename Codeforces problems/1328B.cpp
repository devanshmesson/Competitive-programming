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
        int n,k,a,b,in,j,x,y;
        cin>>n>>k;
        vector<pair<int,int>>v;
        v.push_back(make_pair(1,1));
        for(int i=1;i<n;i++)
        {
           b=v[i-1].second+i+1;
           a=b-i;
           v.push_back(make_pair(a,b));
        }
        for(int i=0;i<n;i++)
        {
            if(k>=v[i].first && k<=v[i].second)
            {
            in=i;break;

            }
        }
        //cout<<in<<endl;
        if(k>v[in].first)
        {

            j=k-v[in].first;
            x=n-(in+2);
            y=n-(j+1);
        }
        else if(k==v[in].first)
        {
            x=n-(in+2);
            y=n-1;
        }

        for(int i=0;i<n;i++)
        {
            if(i==x)cout<<"b";
            else if(i==y)cout<<"b";
            else cout<<"a";
        }
        cout<<endl;
    }
    return 0;
}
