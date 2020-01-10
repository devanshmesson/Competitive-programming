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
        int n,a,q,k,l,ans=1,odd=0,even=0,o,e;
        cin>>n;
        int v[n];
        vector<int>c;
        vector<pair<int,int>>h;

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]%2==0)even++;
            c.push_back(even);
        }

        cin>>q;

        for(int i=0;i<q;i++)
        {
            cin>>k>>l;
            k--;
            l--;
            if(k==0)k++;
            if(abs(c[k-1] - c[l])>0)cout<<"EVEN"<<endl;
            else cout<<"ODD"<<endl;

        }

    }

    return 0;
}
