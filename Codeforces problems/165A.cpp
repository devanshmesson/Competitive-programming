#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,b,cnt1=0,cnt=0,left=0,rit=0,up=0,down=0,ans=0;
    cin>>n;
    vector<pair<int,int> > v;
    vector<int> h;

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    for(int i=0;i<n;i++)
    {
        cnt=0;cnt1=0;
       for(int j=0;j<n;j++)
       if(i!=j) if(v[j].second==v[i].second)cnt++;
       for(int j=0;j<n;j++)
       if(i!=j)if(v[j].first==v[i].first)cnt1++;
       if(cnt>=2 && cnt1>=2)h.push_back(i);
    }
    int s=h.size();
    for(int i=0;i<s;i++)
    {
        left=0;rit=0;up=0;down=0;
        for(int j=0;j<n;j++)
        {
            if(h[i]!=j)
            {
               if(v[h[i]].second==v[j].second)
                {
                 if(v[j].first>v[h[i]].first)rit++;
                 if(v[j].first<v[h[i]].first)left++;
                }
            }
        }
        if(left<1 && rit<1)continue;

        for(int j=0;j<n;j++)
        {
            if(h[i]!=j)
            {
               if(v[h[i]].first==v[j].first)
                {
                 if(v[j].second>v[h[i]].second)up++;
                 if(v[j].second<v[h[i]].second)down++;
                }
            }
        }
        if(up<1 && down<1)continue;
        if(left>=1 && rit>=1 && up>=1 && down>=1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
