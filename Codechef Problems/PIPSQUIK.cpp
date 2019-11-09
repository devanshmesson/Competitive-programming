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
            vector<pair<int,int>>v;
            int n,h,d,u,li,x,bar,cnt=0,b,xi,flag=1;
            cin>>n>>h>>d>>u>>li;
            for(int i=0;i<n;i++)
            {
                cin>>bar>>x;
                v.push_back(make_pair(bar,x));
            }
            for(int i=0;i<n;i++)
            {
                flag=1;
                b=v[i].first; xi=v[i].second;
                if(b==2)
                {
                    if(u>=xi){flag=0;cnt++;}
                }
                else if(b==1)
                {
                    if(h<=xi || h-d<=xi){flag=0;cnt++;}
                }
                if(flag==1 && li!=0)
                {
                    li--;
                    if(li==0)break;
                    cnt++;
                }
            }
            cout<<cnt<<endl;
    }
    return 0;
}
