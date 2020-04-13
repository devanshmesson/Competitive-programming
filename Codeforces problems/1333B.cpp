//B. Kind Anton
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
        int n,f=0,flag=0;
        cin>>n;
        int a[n+10]={0},b[n+10]={0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        if(a[0]!=b[0]){f=1;cout<<"NO"<<endl;continue;}

        for(int i=0;i<n;i++)
        {
            flag=0;
            if(b[i]>a[i])
            {
                for(int j=0;j<i;j++)
                {
                    if(a[j]>=1){flag=1;break;}
                }
                if(flag==0){f=1;break;}
            }
            else if(b[i]<a[i])
            {
                flag=0;
                for(int j=0;j<i;j++)
                {
                    if(a[j]<0){flag=1;break;}
                }
                if(flag==0){f=1;break;}
            }
        }
        if(f==1){cout<<"NO"<<endl;continue;}
        sort(a,a+n);
        sort(b,b+n);
        if(b[0]<0)
        {
            if(a[0]>0){f=1;cout<<"NO"<<endl;continue;}
        }

        if(f==0)cout<<"YES"<<endl;

    }
    return 0;
}
