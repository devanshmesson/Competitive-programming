//code1 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,flag=1;
        vector<int> v,h;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            a=0;
            h.push_back(a);
        }
        for(int i=0;i<m;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i]-1!=j)
                {
                    if(h[v[i]-1]>h[j]){flag=0; break;}
                }
            }
            if(flag==0){cout<<"NO"<<endl;break;}
            h[v[i]-1]++;
        }
        //for(int i=0;i<n;i++)cout<<h[i]<<" ";
        if(flag==1)cout<<"YES"<<endl;
    }
    return 0;
}
