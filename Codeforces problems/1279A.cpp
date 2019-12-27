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
        int r,g,b;
        vector<int>v;
        cin>>r>>g>>b;
        v.push_back(r);
        v.push_back(g);
        v.push_back(b);
        sort(v.begin(),v.end());
int m=v[0];
int n=v[1];
 
        for(int i=0;i<3;i++)
        {
            v[i]=v[i]-m;
        }
        for(int i=1;i<=2;i++)
        {
            v[i]=v[i]-n;
        }
        if(v[2]>1)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
 
 
 
 
 
    }
 
    return 0;
}
