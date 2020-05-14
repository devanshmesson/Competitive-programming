#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int sign(int a)
{
    if(a<0)return -1;
    else if (a>=0)return 1;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,j,m=INT_MIN;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++)cin>>a[i];
        int sum=0,cur;

        for(int i=0;i<n;i++)
        {
         cur=a[i];
         j=i;
         while(j<n && sign(a[i])==sign(a[j]))
         {
             m=max(a[j],m);
             j++;
         }
         sum+=m;
         m=INT_MIN;
         i=j-1;

        }
        cout<<sum<<endl;
    }
}
