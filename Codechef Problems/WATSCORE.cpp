#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,ans=0,sum=0,ans1=0;
        cin>>n;
        int v[11]={0};
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            if(a!=9&&a!=10&&a!=11) v[a]=max(v[a],b);
        }
        for(int i=1;i<=8;i++)
        {
         sum+=v[i];
        }
        cout<<sum<<endl;
    }
}
