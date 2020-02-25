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
        int n,m,v,flag=0,cnt=0,f=0;
        cin>>n>>m;
        vector<int>a,p,h;
        for(int i=0;i<n;i++)
        {
            cin>>v;a.push_back(v);
            h.push_back(v);
        }
        for(int i=0;i<m;i++)
        {
            cin>>v;p.push_back(v);
        }
sort(h.begin(),h.end());
            while(1)
            {
                flag=1;
                cnt=0,f=1;
            for(int i=0;i<m;i++)
            {
                if(a[p[i]-1]>a[p[i]])
                {
                    swap(a[p[i]-1],a[p[i]]);
                }
                else cnt++;
            }
            if(cnt==m){f=0;}

            for(int i=0;i<n;i++)
            {
                if(a[i]!=h[i]){flag=0;break;}
            }
            if(flag==0 && f==0){flag=0;break;}
            else if(flag==1)break;

            }

            if(flag==1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

    }
    return 0;
}
