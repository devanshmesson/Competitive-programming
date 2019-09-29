#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    char c[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>c[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(c[i][j]!='-')
           {
               if((i+j)%2==0)cout<<"W";
               if((i+j)%2!=0)cout<<"B";
           }
           else cout<<"-";
        }
        cout<<endl;
    }


    return 0;
}
