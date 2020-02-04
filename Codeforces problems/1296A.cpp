#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,flag=1,sum=0,f=1;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2!=0)flag=0;
            sum+=a[i];
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0)f=0;
        }
        if(flag==1||f==1)
        {
            if(sum%2==0)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else
        {
        cout<<"YES"<<endl;
 
        }
 
    }
    return 0;
}
