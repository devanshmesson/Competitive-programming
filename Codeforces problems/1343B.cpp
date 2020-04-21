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
        int n;
        cin>>n;
        if((n/2)%2!=0)cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n/2;i++)
            {
                cout<<i*2<<" ";
            }
            int s=n/2,j;


            for(int i=0;i<s;i++)
            {
                if(i==s-1)cout<<2*i+1+(2)*(n/4)<<" ";
                else cout<<2*i+1<<" ";
            }
              cout<<endl;
        }

    }

    return 0;
}
