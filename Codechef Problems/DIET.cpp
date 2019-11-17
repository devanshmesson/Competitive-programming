#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio();cin.tie();cout.tie();
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,a,temp=0,flag=1,t2=0;
        cin>>n>>k;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
           cin>>a;
           v.push_back(a);
        }

        for(int i=0;i<n;i++)
        {
            if(v[i]<k){flag=0;t2=i;break;}
            else if(v[i]>=k){temp=v[i]-k; v[i+1]+=temp;}
        }
        if(flag==0){cout<<"NO"<<" "<<t2+1<<endl;}
        else cout<<"YES"<<endl;

    }
    return 0;
}
