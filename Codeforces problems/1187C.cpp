#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int t[n+1],l[n+1],r[n+1],b[n+1],a[n+1];
    a[1]=n;
    for(int i=1;i<=m;i++)
    {
        cin>>t[i]>>l[i]>>r[i];
    }
    int flag=0;
    for(int i=1;i<n;i++)
    {
        flag=0;
        for(int j=1;j<=m;j++)
        {
            if(t[j]==1)
            {
                if(i>=l[j] && i<r[j])
                {
                    flag=1;
                    b[i]=0;
                    break;
                }
            }
        }
        if(flag==0)b[i]=-1;

    }
        for(int i=2;i<=n;i++)
        {
            a[i]=a[i-1]+b[i-1];
        }

        flag=0;

        for(int i=1;i<=m;i++)
        {
            if(t[i]==0)
            {
                flag=1;
                for(int j=l[i];j<r[i];j++)
                {
                    if(a[j]>a[j+1]){flag=0;break;}
                }
                if(flag==1)break;
            }
            if(flag==1)break;
        }
        if(flag==1)cout<<"NO"<<endl;
        else if(flag==0)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
            {
              cout<<a[i]<<" ";
            }
            cout<<endl;
        }



return 0;
}
