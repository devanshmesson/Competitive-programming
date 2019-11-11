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
        int n,maxm=0,cnt=0,x,r;
        cin>>n;
        string s;
        int t1[50],t2[50];
        vector<string>v;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            v.push_back(s);
        }

        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<10;j++)
            {
                t1[j]=v[i][j]^v[i+1][j];
                v[i+1][j]=t1[j];
            }
        }
        for(int i=0;i<10;i++)
        {
            if(t1[i]==49 || t1[i]==1)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
