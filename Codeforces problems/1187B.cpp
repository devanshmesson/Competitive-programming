#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>pos[130];
    int h;
    for(int i=0;i<n;i++)
    {
        h=(int)s[i];
        pos[h].push_back(i+1);
    }
    int m;
    cin>>m;
    while(m--)
    {
        string t;
        cin>>t;
        int cnt[130]={0},k;
        for(int i=0;i<t.size();i++)
        {
          k=(int)t[i];
          cnt[k]++;
        }
        int ans=-1;
        for(int i=97;i<=122;i++)
        {
            if(cnt[i]>0)
            {
                ans=max(ans,pos[i][cnt[i]-1]);
            }
        }
        cout<<ans<<endl;
    }
}
