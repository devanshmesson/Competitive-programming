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
        int a,b,c,n,sum=0;
        cin>>a>>b>>c>>n;
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end(),greater<int>());
        sum+=v[0]-v[1];
        sum+=v[0]-v[2];
        n-=sum;
        if(n%3==0 && n>=0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
 
 
 
 
 
    }
 
    return 0;
}
