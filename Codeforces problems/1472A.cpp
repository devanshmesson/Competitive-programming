#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"
int main()
{
    freopen
    io
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
     int w,h,n;
     cin>>w>>h>>n;
     int a=__gcd(w,1ll<<14); // Calculating largest power of 2 which can divide w
     int b=__gcd(h,1ll<<14); // Calculating largest power of 2 which can divide h
     //2^14 is taken as reference because its greater than 10^4 (input)
     if(a*b>=n)cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
    }
} 
