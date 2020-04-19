#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
     int n,c=0;
     cin>>n;
     int a[n+100];
     for(int i=0;i<n;i++)cin>>a[i];
     for(int i=1;i<n-1;i++)
     {
         if(a[i]>a[i-1] && a[i]>a[i+1])c++;
     }
     cout<<"Case #"<<j<<": "<<c<<endl;

    }
    return 0;
}
