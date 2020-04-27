#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    //#define endl "\n"
    int t;
    cin>>t;
    while(t--)
    {
        string s,l,r,h;
        cin>>s;
        h=s;
        char q=s[0];
        int n=s.size();
        l+=s[n-1];
        for(int i=0;i<n;i++)
        {
          s[i]=s[i+1];
        }
        s[n-1]=q;

        for(int i=0;i<n-1;i++)
        {
          l+=h[i];
        }
       if(s==l)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;



    }
    return 0;
}
