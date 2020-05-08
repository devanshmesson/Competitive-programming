#include<bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   
     int n,m;
     cin>>n;
     int a[n+1];
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }

     cin>>m;
     int b[m+1];
     for(int i=0;i<m;i++)
     {
         cin>>b[i];
     }
     sort(a,a+n);
     sort(b,b+m);
     cout<<a[n-1]<<" "<<b[m-1]<<endl;

    
}
