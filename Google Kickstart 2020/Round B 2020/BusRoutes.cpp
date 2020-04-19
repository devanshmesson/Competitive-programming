#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
     int n,flag=1,d,x;
     cin>>n>>d;
     //int a[n+100],b[n+100],c[n+100];
     vector<int>a,b,c;
     for(int i=0;i<n;i++){cin>>x;a.push_back(x);c.push_back(x);}
     for(int i=0;i<n;i++)
     {
         a[i]=d-(d%a[i]);
         b.push_back(a[i]);
     }
     sort(b.begin(),b.end());
     for(int i=0;i<n;i++)
     {
         if(a[i]!=b[i])
         {
             flag=0;
         }
     }
     if(flag==1){cout<<"Case #"<<j<<": "<<a[0]<<endl;continue;}

     if(flag==0)
     {
         for(int i=n-1;i>0;i--)
         {
             if(a[i-1]>a[i])
             {
                 int y=a[i-1]-abs(a[i]-a[i-1]);
                 a[i-1]=y-(y%c[i-1]);
             }
         }
     }
     cout<<"Case #"<<j<<": "<<a[0]<<endl;



    }
    return 0;
}
