#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    #define endl "\n"
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,c=1,flag=1;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.pb(a);
        }
    if(n==1){cout<<1<<endl;continue;}
        if(v[0]>=v[1]){c++;}
        else v[1]=v[0];
        for(int i=1;i<n-1;i++)
        {
            if(v[i]>=v[i+1]){c++;flag=0;}
            else v[i+1]=v[i];
            
        }
        cout<<c<<endl;

    }
    return 0;
}


