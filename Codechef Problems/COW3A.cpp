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


    int a,b,c,d;
    cin>>a>>b>>c>>d;

   cout<<a-(b-(d-a))<<" "<<b-(d-a)<<" "<<d-a<<endl;
    }
    return 0;
}
