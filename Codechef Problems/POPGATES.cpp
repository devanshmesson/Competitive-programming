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
        int n,k;
        int t=0,h=0;
        cin>>n>>k;
        char a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]=='T')t++;
            if(a[i]=='H')h++;
        }

        for(int i=n-1;i>n-1-k;i--)
        {
            if(a[i]=='H')
            {

                h--;
                int w=h;
                h=t;
                t=w;
                for(int j=i-1;j>=0;j--)
                {
                    if(a[j]=='H')a[j]='T';
                    else if(a[j]=='T')a[j]='H';
                }
            }
            else if(a[i]=='T')t--;
        }
        cout<<h<<endl;

    }


    return 0;
}
