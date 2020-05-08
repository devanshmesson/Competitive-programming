#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end(),greater<int>());
        cout<<min(v[1]-1,n-2)<<endl;
    }
}
