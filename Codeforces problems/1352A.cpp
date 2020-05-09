#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s;
        vector<string>v;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!='0')
            {
            t+=s[i];
            for(int j=1;j<=s.size()-i-1;j++)t+='0';
            v.push_back(t);
            }
            t.clear();
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}
