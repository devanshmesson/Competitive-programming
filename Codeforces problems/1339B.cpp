//B. Sorted Adjacent Differences
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n;
        vector<int>v,h;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.pb(a);
        }
        sort(v.begin(),v.end());

        for(int i=0,j=n-1;i<n,j>=0;i++,j--)
        {
            if(i>=j && n%2==0)break;
            else if(i>j && n%2!=0){break;}
            if(i==j && n%2!=0){h.pb(v[i]);continue;}
            h.pb(v[i]);
            h.pb(v[j]);
        }
        reverse(h.begin(),h.end());
        for(int i=0;i<h.size();i++)
        {
            cout<<h[i]<<" ";
        }
cout<<endl;
    }
    return 0;
}
