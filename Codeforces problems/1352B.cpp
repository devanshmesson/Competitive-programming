#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>v;

        int n,k;
        cin>>n>>k;
        int k1=k;


        if(n%2==0)
        {
            int g=k-1;
            if((n-g)%2!=0 && (n-g)>0)
            {
                cout<<"YES"<<endl;
                for(int i=0;i<k-1;i++)cout<<1<<" ";
                cout<<n-g<<endl;
                continue;
            }
            else if((n-(2*g))>0  &&  (n-(2*g))%2==0)
            {
                cout<<"YES"<<endl;
                for(int i=0;i<k-1;i++)cout<<2<<" ";
                cout<<n-(2*g)<<endl;
                continue;
            }
            else {cout<<"NO"<<endl;continue;}
        }
        else if(n%2!=0)
        {
            int g=k-1;
            if((n-g)%2!=0 && (n-g)>0)
            {
                cout<<"YES"<<endl;
                for(int i=0;i<k-1;i++)cout<<1<<" ";
                cout<<n-g<<endl;
                continue;
            }
            else {cout<<"NO"<<endl;continue;}
        }

    }
}
