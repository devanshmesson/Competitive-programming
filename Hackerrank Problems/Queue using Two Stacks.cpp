#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    int t,a,b;
    cin>>t;
    int c=0;
     vector<int>v;
    while(t--)
    {

        cin>>a;
        if(a==1)
        {
            cin>>b;
            v.push_back(b);
        }
        else if(a==2)
        {
           c++;
        }
        else if(a==3)
        {
            cout<<v[c]<<endl;
        }
    }
}
