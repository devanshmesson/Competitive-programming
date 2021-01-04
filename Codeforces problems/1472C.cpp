#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"

int main()
{
    io
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     int a[n+1];
     for(int i=1;i<=n;i++) cin>>a[i];
     int score[n+1]={0};
     int maxi=-1;
     for(int i=n;i>=1;i--)
     {
      if(i+a[i]>n)score[i]=a[i];
      else score[i]=score[i+a[i]]+a[i];
      maxi=max(maxi,score[i]);
     }
     cout<<maxi<<endl;
    }
} 
