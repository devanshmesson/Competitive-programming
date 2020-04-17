#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    int n;
    cin>>n;
    int a[n+100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);

    int v=INT_MAX;
    //cout<<a[0]<<" "<<a[1];
    for(int i=0;i<n-1;i++)
    {
        v=min(v,abs(a[i]-a[i+1]));
    }

    for(int i=0;i<n-1;i++)
    {
        if(abs(a[i]-a[i+1])==v)
        {
            cout<<a[i]<<" "<<a[i+1]<<" ";
        }
    }
}
